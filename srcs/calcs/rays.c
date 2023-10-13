/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/13 19:38:45 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	print_screen(t_cube *cube, double *arr)
{
	int	x;
	int	y;
	int	height;
	double	angle = 60.0;

	x = -1;
	while (++x < 1200)
	{
		y = -1;
		arr[x] *= cos((-90.0 + angle) * cube->rad_const);
		angle += 60.0 / 1200.0;
		height = (64.0 / arr[x]) * cube->length_ray;
		while (++y < 1200)
		{
			if (y > 600 - (height / 2) && y < 600 + (height / 2))
				my_mlx_pixel_put(&cube->mlx, x, y, 0xFF0000);
			else
				my_mlx_pixel_put(&cube->mlx, x, y, 0x808080);
		}
	}
}

void	calculate_rays(t_cube *cube)
{
	int	idx;
	int	check;
	int	offset;
	double	paX;
	double	paY;
//	double	pbX;
//	double	pbY;
	double	angle;
	double	startX;
	double	startY;
	double	firstXa;
	double	otherXa;
	double	distance[1201];

	idx = 1200;
	angle = 60.0;
	while (angle < 120.0)
	{
		startX = (double)cube->nposX; //416.00
		startY = (double)cube->nposY; //416.00
		if (angle == 90.0)
		{
			firstXa = 0.0;
			otherXa = 0.0;
		}
		else
		{
			if (cube->nposY % 64 == 0)
				firstXa = 64.0 / tan(angle * cube->rad_const); //18.4752086
			else
				firstXa = (double)(cube->nposY % 64) / tan(angle * cube->rad_const); //18.4752086
			otherXa = 64.0 / tan(angle * cube->rad_const); //36.9504172
		}
		check = false;
		offset = 1;
		paX = startX + firstXa; //434.4752086
		while (!check)
		{
			if (cube->iY - offset < 0 || cube->map[cube->iY - offset][(int)fabs(paX / 64)] == '1')
				check = true;
			else
			{
				paX += otherXa;
				offset++;
			}
		}
		paY = (double)(cube->iY - offset + 1) * 64.0;
		distance[idx] = sqrt(pow(paX - startX, 2) + pow(paY - startY, 2));
		angle += 60.0 / 1200.0;
		idx--;
	}
	print_screen(cube, distance);
//	double	firstYb = 32.0 * tan(60.0 * cube->rad_const); //18.4752086
//	double	otherYb = 64.0 * tan(60.0 * cube->rad_const); //36.9504172
//	check = false;
//	offset = 1;
//	pbY = startX + firstYb; //434.4752086
//	while (!check)
//	{
//		if (cube->nposY + offset >= (int)ft_strlen(cube->map[0]) || cube->map[(int)fabs(pbY / 64)][cube->nposY + offset] == '1')
//			check = true;
//		else
//		{
//			pbY += otherYb;
//			offset++;
//		}
//	}
//	pbX = (double)(cube->nposX + offset) * 64.0;
//	float	distance_b = sqrt(pow(pbX - startX, 2) + pow(pbY - startY, 2));
//	printf("PbX: %f\tPbY: %f\tX: %d\tY: %d\tDistance: %f\n", pbX, pbY, (int)fabs(paX / 64), cube->nposY - offset, distance_b);
}
