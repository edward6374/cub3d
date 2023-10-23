/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/19 19:28:24 by vduchi           ###   ########.fr       */
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

int	double_equals(double a, double b)
{
    return fabs(a - b) < 0.001;
}

int	angle_control(t_cube *cube, t_rays *r, double angle, int mode)
{
	(void)cube; //porque aun no utilizo el angulo en la estructura
	if (double_equals(angle, 90.000000) || double_equals(angle, 270.000000)) //tan con angulo de 90 y 270 es infinito
	{
		if (!mode)
		{
			r->long_seg = 0.00;
			r->small_seg = 0.00;
		}
		else
		{
			r->long_seg = 5000.00;
			r->small_seg = 5000.00;
		}
		return (1);
	}
	return (0);
}

void	check_segments(t_cube *cube, t_rays *r, double angle, int mode) //mode 0 es el calculo de la X, 1 de la Y
{
	r->offset = 1;
	if (!angle_control(cube, r, angle, mode))
	{
		if (!mode)
		{
			if (double_equals(angle, 0.0) || double_equals(angle, 180.0))
			{
				r->small_seg = (double)(cube->nposY % 64);
				r->long_seg = 64.0;
			}
			else 
			{
				if (cube->nposY % 64 == 0)
					r->small_seg = 64.0 / tan(angle * cube->rad_const);
				else
					r->small_seg = (double)(cube->nposY % 64) / tan(angle * cube->rad_const);
				r->long_seg = 64.0 / tan(angle * cube->rad_const);
			}
		}
		else
		{
			if (double_equals(angle, 90.0) || double_equals(angle, 270.0))
			{
				r->small_seg = (double)(cube->nposX % 64);
				r->long_seg = 64.0;
			}
			else
			{
				if (cube->nposX % 64 == 0)
					r->small_seg = 64.0 * tan(angle * cube->rad_const);
				else
					r->small_seg = (double)(cube->nposX % 64) * tan(angle * cube->rad_const);
				r->long_seg = 64.0 * tan(angle * cube->rad_const);
			}
		}
	}
	if (!mode)
	{
		r->p_x = r->start_x + r->small_seg;
//		printf("R_X: %f\n", r->p_x);
	}
	else
	{
		r->p_y = r->start_y + r->small_seg;
//		printf("R_Y: %f\n", r->p_y);
	}
}

double	bigger_distance(t_cube *cube, t_rays r, double angle) //despues angle es de la estructura cube
{
	check_segments(cube, &r, angle, 0);
	while ((int)(cube->nposY / 64.0) - r.offset >= 0 && cube->map[(int)(cube->nposY / 64.0) - r.offset][(int)fabs(r.p_x / 64.0)] != '1')
	{
//		printf("First\tX: %d\tY: %d\n", (int)(cube->nposY / 64.0) - r.offset, (int)fabs(r.p_x / 64.0));
		r.p_x += r.long_seg;
		r.offset++;
	}
	if (double_equals(angle, 90.0) || double_equals(angle, 270.0))
	{
		r.p_y = (double)((int)(cube->nposY / 64) - r.offset + 1) * 64.0; //No necesito la y cuando tengo la x y igual al revers
		r.dist_x = (fabs((r.start_y - r.p_y) / sin(angle * cube->rad_const))); //* cos((-90.0 + angle) * cube->rad_const);
	}
	else
		r.dist_x = (fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const))); //* cos((-90.0 + angle) * cube->rad_const);
	check_segments(cube, &r, angle, 1);
	while ((int)fabs(r.p_y / 64.0) < (int)ft_strlen(cube->map[0]) && (int)(cube->nposX / 64.0) + r.offset < (int)ft_strlen(cube->map[0])
			&& cube->map[(int)fabs(r.p_y / 64.0)][(int)(cube->nposX / 64.0) + r.offset] != '1')
	{
//		printf("Second\tX: %d\tY: %d\tLen: %d\n", (int)fabs(r.p_y / 64.0), (int)(cube->nposX / 64.0) + r.offset, (int)ft_strlen(cube->map[0]));
		r.p_y += r.long_seg;
		r.offset++;
	}
	if (double_equals(angle, 0.0) || double_equals(angle, 180.0))
	{
		r.p_x = (double)(cube->nposX + r.offset) * 64.0;
		r.dist_x = (fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const))); //* cos((-90.0 + angle) * cube->rad_const);
	}
	else
		r.dist_y = (fabs((r.start_y - r.p_y) / sin(angle * cube->rad_const))); // * cos((-90.0 + angle) * cube->rad_const);
//	printf("Angle: %f\tDist X: %f\tDist Y: %f\n", angle, r.dist_x, r.dist_y);
	if (r.dist_x < r.dist_y)
		return (r.dist_x);
	return (r.dist_y);
}

void	calculate_rays(t_cube *cube)
{
	int	idx;
	double	angle;
	double	distance[1200];
	t_rays	r;

	r.offset = 1;
	r.start_x = (double)cube->nposX;
	r.start_y = (double)cube->nposY;
	idx = 1199;
//	angle = 60.0; //despues angle = cube->angle
	angle = cube->angle - 30.0;
	printf("Angle before: %f\n", angle);
	while (angle < cube->angle + 29.9999)
	{
		distance[idx] = bigger_distance(cube, r, angle);
		distance[idx] *= cos((-90 + angle) * cube->rad_const);
		printf("Distance: %f\tIdx: %d\n", distance[idx], idx);
		angle += 60.00 / 1200.00;
		idx--;
	}
	printf("Angle after: %f\n", angle);
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
