/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/14 19:18:11 by vduchi           ###   ########.fr       */
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
//		arr[x] *= cos((-90.0 + angle) * cube->rad_const);
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

void	check_segments(t_cube *cube, t_rays *r, double angle, int mode)
{
	if (angle == 90.0)
	{
		r->long_seg = 0.00;
		r->small_seg = 0.00;
	}
	else
	{
		if (cube->nposY % 64 == 0)
			r->small_seg = 64.0 / tan(angle * cube->rad_const);
		else
		{
			if (!mode)
				r->small_seg = (double)(cube->nposY % 64) / tan(angle * cube->rad_const);
			else
				r->small_seg = (double)(cube->nposX % 64) / tan(angle * cube->rad_const);
		}
		r->long_seg = 64.0 / tan(angle * cube->rad_const);
	}
}

double	bigger_distance(t_cube *cube, t_rays r, double angle) //despues angle es de la estructura cube
{
	check_segments(cube, &r, angle, 0);
	r.p_x = r.start_x + r.small_seg;
	while (42)
	{
		if ((int)(cube->nposY / 64) - r.offset < 0 || cube->map[(int)(cube->nposY / 64) - r.offset][(int)fabs(r.p_x / 64)] == '1')
			break ;
		r.p_x += r.long_seg;
		r.offset++;
	}
	r.p_y = (double)((int)(cube->nposY / 64) - r.offset + 1) * 64.0;
	r.dist_x = (fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const))) * cos((-90.0 + angle) * cube->rad_const);
	r.offset = 1;
	check_segments(cube, &r, angle, 1);
	r.p_y = r.start_y + r.small_seg;
	while (42)
	{
		if (cube->nposY + r.offset >= (int)ft_strlen(cube->map[0]) || cube->map[(int)fabs(r.p_y / 64)][cube->nposY + r.offset] == '1')
			break ;
		r.p_y += r.long_seg;
		r.offset++;
	}
	r.p_x = (double)(cube->nposX + r.offset) * 64.0;
	r.dist_y = (fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const))) * cos((-90.0 + angle) * cube->rad_const);
	if (r.dist_x > r.dist_y)
		return (r.dist_x);
	return (r.dist_y);
}

void	calculate_rays(t_cube *cube)
{
	int	idx;
//	int	check;
//	int	offset;
//	double	paX;
//	double	paY;
//	double	pbX;
//	double	pbY;
	double	angle;
//	double	startX;
//	double	startY;
//	double	firstXa;
//	double	otherXa;
	double	distance[1200];
	t_rays	r;

	r.offset = 1;
	r.start_x = (double)cube->nposX;
	r.start_y = (double)cube->nposY;
	idx = 1199;
	angle = 60.0; //despues angle = cube->angle
	while (angle < 120.0)
	{
		distance[idx] = bigger_distance(cube, r, angle);
		angle += 60.00 / 1200.00;
		idx--;
//		startX = (double)cube->nposX; //416.00
//		startY = (double)cube->nposY; //416.00
//		if (angle == 90.0)
//		{
//			firstXa = 0.0;
//			otherXa = 0.0;
//		}
//		else
//		{
//			if (cube->nposY % 64 == 0)
//				firstXa = 64.0 / tan(angle * cube->rad_const);
//			else
//				firstXa = (double)(cube->nposY % 64) / tan(angle * cube->rad_const); //18.4752086
//			otherXa = 64.0 / tan(angle * cube->rad_const); //36.9504172
//		}
//		check = false;
//		offset = 1;
//		paX = startX + firstXa; //434.4752086
//		while (!check)
//		{
//			if ((int)(cube->nposY / 64) - offset < 0 || cube->map[(int)(cube->nposY / 64) - offset][(int)fabs(paX / 64)] == '1')
//				check = true;
//			else
//			{
//				paX += otherXa;
//				offset++;
//			}
//		}
//		paY = (double)((int)(cube->nposY / 64) - offset + 1) * 64.0;
//		distance[idx] = (fabs((startY - paY) / sin(angle * cube->rad_const))) * cos((-90.0 + angle) * cube->rad_const);
//		angle += 60.0 / 1200.0;
//		idx--;
//		distance[idx] = sqrt(pow(paX - startX, 2) + pow(paY - startY, 2)); //calculo muy lento
//		printf("Distance: %f\n", distance[idx]);
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
