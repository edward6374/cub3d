/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:39 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/04 17:03:36 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int map_max_len(t_cube *cube, int mode)
{
	int i;
	int max;

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

void print_minimap(t_cube *cube, int max_x, int max_y, int offset, int dir)
{
	(void)cube;
	(void)max_x;
	(void)max_y;
	(void)dir;
	(void)offset;
}

void which_colour(t_cube *cube, double *xy, int *idx, int *i)
{
	if (xy[X] < 0.00 || xy[Y] < 0.00 || idx[X] >= cube->rows
		|| idx[Y] >= (int)ft_strlen(cube->map[idx[X]])
		|| cube->map[idx[X]][idx[Y]] == '1' || cube->map[idx[X]][idx[Y]] == ' ')
		my_mlx_pixel_put(&cube->mlx, i[X], i[Y], 0x242C5F);
	else if (xy[X] >= cube->nposX - 8.00 && xy[X] <= cube->nposX + 8.00
		&& xy[Y] >= cube->nposY - 8.00 && xy[Y] <= cube->nposY + 8.00)
		my_mlx_pixel_put(&cube->mlx, i[X], i[Y], 0x00FF00);
	else
		my_mlx_pixel_put(&cube->mlx, i[X], i[Y], 0x97A3F0);
}

void create_minimap(t_cube *cube)
{
	int i[2];
	int idx[2];
	double xy[2];

	xy[X] = cube->nposX - 320.00;
	xy[Y] = cube->nposY - 192.00;
	i[X] = 20;
	while (xy[X] <= cube->nposX + 320.00)
	{
		i[Y] = 20;
		xy[Y] = cube->nposY - 192.00;
		while (xy[Y] <= cube->nposY + 192.00)
		{
			idx[X] = (int)fabs(xy[Y] / 64.00);
			idx[Y] = (int)fabs(xy[X] / 64.00);
			which_colour(cube, xy, idx, i);
			xy[Y] = xy[Y] + 2.00;
			i[Y]++;
		}
		i[X]++;
		xy[X] = xy[X] + 2.00;
	}
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
}

void hook_mlx(t_cube *cube)
{
	calculate_rays(cube);
	create_minimap(cube);
	cube->mlx.status = 0;
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
	mlx_key_hook(cube->mlx.win, key_hook, cube);
	mlx_mouse_hook(cube->mlx.win, mouse_hook, cube);
	mlx_hook(cube->mlx.win, 17, 0, exit_safe, cube);
	mlx_hook(cube->mlx.win, 2, 1L << 0, keep_pressed, cube);
	mlx_loop_hook(cube->mlx.mlx, loop_hook, cube);
	mlx_loop(cube->mlx.mlx);
}

int init_mlx(t_cube *cube)
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
	hook_mlx(cube);
	return (0);
}
