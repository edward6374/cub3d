/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:09:32 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/08 10:58:37 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs.h"
#include <math.h>

void	print_pixel(t_cube *cube, int x, int y, t_color colors)
{
	my_mlx_pixel_put(&cube->mlx, x, y, ((0 & 0xff) << 24) + \
	   ((colors.r & 0xff) << 16) + ((colors.g & 0xff) << 8) + \
	   ((colors.b & 0xff)));
}

int	check_x(t_cube *cube, int idx)
{
	int		ret;
	double	min;
	double	max;
	double	diff;
	double	piece;

	diff = fmodf(cube->walls.pos[idx], 64.00);
	min = cube->walls.pos[idx] - diff;
	max = min + 64.00;
	piece = (max - min) / 5.00;
	ret = (int)round(((fmodf(cube->walls.pos[idx] - min, piece) * 64.00) / piece));
	if (ret == 64)
		ret = 0;
	return (ret);
}

void	print_image(t_cube *cube, double height, int x, int y)
{
	int		idx;
	double	min;
	double	max;
	double	piece;
	char	*find;
	t_color	*rgb;

	min = ((double)cube->height / 2.00) - height;
	max = ((double)cube->height / 2.00) + height;
	piece = (max - min) / 5.00;
	idx = (int)round(((fmodf((double)y - min, piece) * 64.00) / piece));
	if (idx == 64)
		idx = 0;
	find = find_char(&cube->img[cube->walls.dir[x]], idx, check_x(cube, x));
	rgb = find_rgb(cube->img[cube->walls.dir[x]].lst, find, cube->img->measures[CHAR]);
	print_pixel(cube, x, y, *rgb);
	free(find);
//	if (cube->walls.dir[x] == NO)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0x00CC00); //verde
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0x00CC66);
//	}
//	else if (cube->walls.dir[x] == SO)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xCC99FF); //lilla
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xE2C4FF);
//	}
//	else if (cube->walls.dir[x] == WE)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFF9933); //arancio
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFFB76E);
//	}
//	else if (cube->walls.dir[x] == EA)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFF99CC); //rosa
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFFB9DC);
//	}
}

void	print_screen(t_cube *cube, double *arr)
{
	int		x;
	int		y;
	double	height;

	x = -1;
	while (++x < cube->width)
	{
		y = -1;
		height = ((64.00 / arr[x]) * cube->length_ray) / 2.00;
		while (++y < cube->height)
		{
			if ((double)y > (double)(cube->height / 2.00) - height
				&& (double)y < (double)(cube->height / 2.00) + height)
				print_image(cube, height, x, y);
			else if ((double)y < (double)(cube->height / 2.00) - height)
				print_pixel(cube, x, y, cube->params.colors[C]);
			else
				print_pixel(cube, x, y, cube->params.colors[F]);
		}
	}
}
