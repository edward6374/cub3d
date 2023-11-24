/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:39 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/24 15:39:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	map_max_len(t_cube *cube, int mode)
{
	int	i;
	int	max;

	max = -1;
	if (!mode)
	{
		i = -1;
		while (cube->map[++i])
			if ((int)ft_strlen(cube->map[i]) > max)
				max = ft_strlen(cube->map[i]);
		return (max);
	}
	else
	{
		i = 0;
		while (cube->map[i])
			i++;
		return (i);
	}
}

void	print_minimap(t_cube *cube, int max_x, int max_y, int offset, int dir)
{
	(void)cube;
	(void)max_x;
	(void)max_y;
	(void)dir;
	(void)offset;
}

void	create_minimap(t_cube *cube, int dir)
{
	int		i;
	int		j;
	int		offset;
	int		idx_x;
	int		idx_y;
	double	x;
	double	y;

	// int		max_x;
	// int		max_y;
	dir = 0; // TODO comentar
	x = cube->posX - 320.00;
	y = cube->posY - 192.00;
	offset = 20;
	i = offset;
	// max_x = 320; // multiplos de 32
	// max_y = 192;
	while (x <= cube->posX + 320.00)
	{
		j = offset;
		y = cube->posY - 192.00;
		idx_x = (int)fabs(y / 64.00);
		idx_y = (int)fabs(x / 64.00);
		// printf("Idx x: %d\tIdx Y: %d\tX: %f\tY: %f\n", idx_x, idx_y, x, y);
		while (y <= cube->posY + 192.00)
		{
			idx_x = (int)fabs(y / 64.00);
			idx_y = (int)fabs(x / 64.00);
			if (x < 0.00 || y < 0.00 || idx_x >= cube->rows
				|| idx_y >= (int)ft_strlen(cube->map[idx_x])
				|| cube->map[idx_x][idx_y] == '1'
				|| cube->map[idx_x][idx_y] == ' ')
				my_mlx_pixel_put(&cube->mlx, i, j, 0x242C5F);
			else if (x >= cube->posX - 10.00 && x <= cube->posX + 10.00
				&& y >= cube->posY - 10.00 && y <= cube->posY + 10.00)
				my_mlx_pixel_put(&cube->mlx, i, j, 0x00FF00);
			else
				my_mlx_pixel_put(&cube->mlx, i, j, 0x97A3F0);
			y = y + 2.00;
			j++;
		}
		i++;
		x = x + 2.00;
	}
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
	//	print_minimap(cube, max_x, max_y, offset, dir);
}

void	hook_mlx(t_cube *cube)
{
	calculate_rays(cube);
	create_minimap(cube, -1);
	cube->mlx.status = 0;
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
	mlx_key_hook(cube->mlx.win, key_hook, cube);
	mlx_mouse_hook(cube->mlx.win, mouse_hook, cube);
	mlx_hook(cube->mlx.win, 17, 0, exit_safe, cube);
	mlx_hook(cube->mlx.win, 2, 1L << 0, keep_pressed, cube);
	mlx_loop_hook(cube->mlx.mlx, loop_hook, cube);
	mlx_loop(cube->mlx.mlx);
}

void init_img(void *mlx, char **path, char *img[])
{
	int i = 0;
	int len;

	while (path[i])
	{
		img[i] = mlx_xpm_file_to_image(mlx, path[i], &len, &len);
		i++;
	}
}

int	init_mlx(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	if (!cube->mlx.mlx)
		return (1);
	cube->mlx.win = mlx_new_window(cube->mlx.mlx, cube->width, cube->height,
		"cub3d");
	if (!cube->mlx.win)
		return (2);
	cube->mlx.img = mlx_new_image(cube->mlx.mlx, cube->width, cube->height);
	if (!cube->mlx.img)
		return (3);
	cube->mlx.addr = mlx_get_data_addr(cube->mlx.img, &cube->mlx.bits_per_pixel,
		&cube->mlx.line_length, &cube->mlx.endian);
	if (!cube->mlx.addr)
		return (4);

	init_img(cube->mlx.mlx, cube->params.path, cube->params.img);
	hook_mlx(cube);
	return (0);
}
