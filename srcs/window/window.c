/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:39 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/28 08:26:07 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void    hook_mlx(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 1920)
	{
		j = -1;
		while (++j < 1020)
		{
			my_mlx_pixel_put(&cube->mlx, i, j, 0x00FF00);
		}
	}
    mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, \
		cube->mlx.img, 0, 0);
	cube->mlx.status = 0;
	mlx_key_hook(cube->mlx.win, key_hook, cube);
	mlx_mouse_hook(cube->mlx.win, mouse_hook, cube);
	mlx_hook(cube->mlx.win, 17, 0, exit_safe, cube);
	mlx_loop_hook(cube->mlx.mlx, loop_hook, cube);
	mlx_loop(cube->mlx.mlx);
}

int init_mlx(t_cube *cube)
{
    int width = 1920;
    int height = 1020;
    cube->mlx.mlx = mlx_init();
	if (!cube->mlx.mlx)
		return (1);
    cube->mlx.win = mlx_new_window(cube->mlx.mlx, width, height, "cub3d");
	if (!cube->mlx.win)
		return (2);
    cube->mlx.img = mlx_new_image(cube->mlx.mlx, width, height);
	if (!cube->mlx.img)
		return (3);
    cube->mlx.addr = mlx_get_data_addr(cube->mlx.img, \
			&cube->mlx.bits_per_pixel, \
			&cube->mlx.line_length, &cube->mlx.endian);
	if (!cube->mlx.addr)
		return (4);
    hook_mlx(cube);
    return (0);
}