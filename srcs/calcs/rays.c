/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/02 17:02:29 by vduchi           ###   ########.fr       */
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
//		arr[x] *= cos((-90.0 + angle) * cube->rad_const); //lo hago antes de esta funcion
		height = (64.0 / arr[x]) * cube->length_ray;
		while (++y < 1200)
		{
			if (y > 600 - (height / 2) && y < 600 + (height / 2))
				my_mlx_pixel_put(&cube->mlx, x, y, 0xFF0000);
			else if (y < 600 - (height / 2))
				my_mlx_pixel_put(&cube->mlx, x, y, ((0 & 0xff) << 24) + \
					((cube->params.colors[1].r & 0xff) << 16) + \
					((cube->params.colors[1].g & 0xff) << 8) + \
					((cube->params.colors[1].b & 0xff)));
			else
				my_mlx_pixel_put(&cube->mlx, x, y, ((0 & 0xff) << 24) + \
					((cube->params.colors[0].r & 0xff) << 16) + \
					((cube->params.colors[0].g & 0xff) << 8) + \
					((cube->params.colors[0].b & 0xff)));
		}
		angle += 60.0 / 1200.0;
	}
	printf("Screen printed\n");
}

double	calc_small(t_cube *cube, double pos, double angle, int mode)
{
	double	diff_x;
	double	diff_y;
	double	tan_value;
	double	just_angle;

	tan_value = tan(angle);
	just_angle = angle / cube->rad_const;
//	printf("X: %d\tY: %d\tNposX: %f\tNposY: %f\tAngle: %f\n", cube->iX, cube->iY, cube->nposX, cube->nposY, angle);
	if (!mode)
	{
		if (double_equals(just_angle, 0.00) || double_equals(just_angle, 180.00)
			|| (just_angle > 0.00 && just_angle < 180.00))
		{
//			printf("Mode 0 yes if\n");
			return (fmod(cube->nposY, 64.00) / tan_value);
		}
//		printf("Mode 0 no if: %f\tTan: %f\n", (((((double)cube->iY + 1.00) * 64.00) - pos) / tan(angle)), tan(angle));
		diff_x = ((cube->iY + 1) * 64.00) - pos;
		return (diff_x / tan_value);
	}
	else
	{
		if (double_equals(just_angle, 90.00) || double_equals(just_angle, 270.00)
			|| (angle / cube->rad_const > 90.00 && angle / cube->rad_const < 270.00))
		{
//			printf("Mode 1 yes if\n");
			return (fmod(cube->nposX, 64.00) * tan_value);
		}
//		printf("Mode 1 no if\n");
		diff_y = ((cube->iX + 1) * 64.00) - pos;
		return (diff_y  * tan_value);
	}
}

void	check_segments(t_cube *cube, t_rays *r, double angle, int mode) //mode 0 es el calculo de la X, 1 de la Y
{
	if (((double_equals(angle, 0.00) || (angle > 0.00 && angle < 180.00)) && !mode)
		|| ((double_equals(angle, 90.00) || (angle > 90.00 && angle < 270.00)) && mode))
	{
		r->incr = -1;
		r->offset = 1; //TODO: es -1
	}
	else
	{
		r->incr = 1;
		r->offset = 1;
	}
	if (double_equals(angle, 0.00) || double_equals(angle, 180.00))
	{
		((!mode) && (set_segments(r, 50000.00, 100000.00)));
		((mode) && (set_segments(r, 0.00, 0.00)));
	}
	else if (double_equals(angle, 90.00) || double_equals(angle, 270.00))
	{
		((!mode) && (set_segments(r, 0.00, 0.00)));
		((mode) && (set_segments(r, 50000.00, 100000.00)));
	}
	else
	{
//		((!mode) && (set_segments(r, (double)((int)cube->nposY % 64) / tan(angle * cube->rad_const), 64.0 / tan(angle * cube->rad_const))));
//		((mode) && (set_segments(r, (double)((int)cube->nposX % 64) * tan(angle * cube->rad_const), 64.0 * tan(angle * cube->rad_const))));
		((!mode) && (set_segments(r, calc_small(cube, cube->nposY, angle * cube->rad_const, 0), 64.0 / tan(angle * cube->rad_const))));
		((mode) && (set_segments(r, calc_small(cube, cube->nposX, angle * cube->rad_const, 1), 64.0 * tan(angle * cube->rad_const))));
	}
	if (!mode)
	{
		if (double_equals(angle, 0.00) || (angle > 0.00 && angle < 180.00))
			r->p_x = r->start_x + r->small_seg;
		else
			r->p_x = r->start_x - r->small_seg;
//		printf("Mode 0: %f\tSmall: %f\tLong %f\tR_X: %f\n", r->start_x, r->small_seg, r->long_seg, r->p_x);
	}
	else
	{
		if (double_equals(angle, 90.00) || (angle > 90.00 && angle < 270.00))
			r->p_y = r->start_y + r->small_seg;
		else
			r->p_y = r->start_y - r->small_seg;
//		printf("Mode 1: %f\tSmall: %f\tLong %f\tR_Y: %f\n", r->start_y, r->small_seg, r->long_seg, r->p_y);
	}
}

double	bigger_distance(t_cube *cube, t_rays r, double angle) //TODO: no strlen ma la longitud de cada linea del mapa
{
	check_segments(cube, &r, angle, 0);
	if (double_equals(angle, 0.00) || (angle > 0.00 && angle < 180.00))
	{
//		printf("First\tX: %d\tY: %d\tR_X: %f\n", (int)(cube->nposY / 64.0) - r.offset, (int)fabs(r.p_x / 64.0), r.p_x);
		while ((int)fabs(r.p_x / 64.00) < (int)ft_strlen(cube->map[0]) && (int)(fabs(cube->nposY / 64.00)) - r.offset >= 0
				&& cube->map[(int)(fabs(cube->nposY / 64.00)) - r.offset][(int)fabs(r.p_x / 64.00)] != '1')
		{
			r.p_x += r.long_seg;
			r.offset++;
//			printf("First\tX: %d\tY: %d\tR_X: %f\n", (int)(cube->nposY / 64.0) - r.offset, (int)fabs(r.p_x / 64.0), r.p_x);
		}
	}
	else
	{
//		printf("Second X\tX: %d\tY: %d\tR_X: %f\n", (int)(cube->nposY / 64.0) + r.offset, (int)fabs(r.p_x / 64.0), r.p_x);
		while ((int)fabs(r.p_x / 64.00) < (int)ft_strlen(cube->map[0]) && (int)(fabs(cube->nposY / 64.00)) + r.offset < 15
				&& cube->map[(int)(fabs(cube->nposY / 64.00)) + r.offset][(int)fabs(r.p_x / 64.00)] != '1')
		{
			r.p_x -= r.long_seg;
			r.offset++;
//			printf("Second\tX: %d\tY: %d\tR_X: %f\n", (int)(cube->nposY / 64.0) + r.offset, (int)fabs(r.p_x / 64.0), r.p_x);
		}
	}
//	while ((int)(cube->nposY / 64.0) + r.offset >= 0 && (int)(cube->nposY / 64.0) + r.offset < 15
//			&& cube->map[(int)(cube->nposY / 64.0) - r.offset][(int)fabs(r.p_x / 64.0)] != '1')
//	{
//		printf("First\tX: %d\tY: %d\n", (int)(cube->nposY / 64.0) - r.offset, (int)fabs(r.p_x / 64.0));
//		r.p_x += r.long_seg;
//		r.offset += r->incr;
//	}
	if (double_equals(angle, 90.00))
	{
		r.p_y = (double)((int)(fabs(cube->nposY / 64.00)) - r.offset + 1) * 64.0; //No necesito la y cuando tengo la x y igual al revers
		r.dist_x = (fabs((r.start_y - r.p_y) / sin(angle * cube->rad_const))); //* cos((-90.0 + angle) * cube->rad_const);
	}
	else if (double_equals(angle, 270.00))
	{
		r.p_y = (double)((int)(fabs(cube->nposY / 64.00)) + r.offset) * 64.0; //No necesito la y cuando tengo la x y igual al revers
		r.dist_x = (fabs((r.start_y - r.p_y) / sin(angle * cube->rad_const))); //* cos((-90.0 + angle) * cube->rad_const);
	}
	else
		r.dist_x = (fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const))); //* cos((-90.0 + angle) * cube->rad_const);
	check_segments(cube, &r, angle, 1);
	if (double_equals(angle, 90.00) || (angle > 90.0 && angle < 270.0))
	{
//		printf("First Y\tX: %d\tY: %d\tR_Y: %f\n", (int)fabs(r.p_y / 64.0), (int)(cube->nposX / 64.0) - r.offset, r.p_y);
		while ((int)fabs(r.p_y / 64.00) < 15 && (int)(fabs(cube->nposX / 64.00)) - r.offset > 0
				&& cube->map[(int)fabs(r.p_y / 64.0)][(int)(fabs(cube->nposX / 64.00)) - r.offset] != '1')
		{
			r.p_y += r.long_seg;
			r.offset++;
//			printf("First Y\tX: %d\tY: %d\tR_Y: %f\n", (int)fabs(r.p_y / 64.0), (int)(cube->nposX / 64.0) - r.offset, r.p_y);
		}
	}
	else
	{
//		printf("Second Y\tX: %d\tY: %d\tR_Y: %f\n", (int)fabs(r.p_y / 64.0), (int)(cube->nposX / 64.0) + r.offset, r.p_y);
		while ((int)fabs(r.p_y / 64.00) < 15 && (int)(fabs(cube->nposX / 64.00)) + r.offset < (int)ft_strlen(cube->map[0])
				&& cube->map[(int)fabs(r.p_y / 64.0)][(int)(fabs(cube->nposX / 64.00)) + r.offset] != '1')
		{
			r.p_y -= r.long_seg;
			r.offset++;
//			printf("Second Y\tX: %d\tY: %d\tR_Y: %f\n", (int)fabs(r.p_y / 64.0), (int)(cube->nposX / 64.0) + r.offset, r.p_y);
		}
	}
	if (double_equals(angle, 0.00))
	{
		r.p_x = (double)((int)(fabs(cube->nposX / 64.00)) + r.offset) * 64.00;
		r.dist_y = fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const)); //* cos((-90.0 + angle) * cube->rad_const);
	}
	else if (double_equals(angle, 180.00))
	{
		r.p_x = (double)((int)(fabs(cube->nposX / 64.00)) - r.offset + 1) * 64.00;
		r.dist_y = fabs((r.start_x - r.p_x) / cos(angle * cube->rad_const)); //* cos((-90.0 + angle) * cube->rad_const);
	}
	else
		r.dist_y = fabs((r.start_y - r.p_y) / sin(angle * cube->rad_const)); // * cos((-90.0 + angle) * cube->rad_const);
//	printf("Angle: %f\tDist X: %f\tDist Y: %f\n\n", angle, r.dist_x, r.dist_y);
	if (r.dist_x <= r.dist_y)
		return (r.dist_x);
	return (r.dist_y);
}

void	calculate_rays(t_cube *cube)
{
	int	idx;
	double	diff;
	double	angle;
	double	cos_angle;
	double	distance[1201];
	t_rays	r;

	r.offset = 1;
	r.start_x = cube->nposX;
	r.start_y = cube->nposY;
	idx = 1200;
	diff = 0.00;
	cos_angle = 30.00;
	if (cube->angle - 30.00 < 0.00)
	{
		angle = 360.00 - (30.00 - cube->angle);
		diff = 30.00 - cube->angle;
	}
	else if (cube->angle + 30.00 > 360.00)
	{
		angle = cube->angle - 30.00;
		diff = 30.00 - (360.00 - cube->angle);
	}
	else
		angle = cube->angle - 30.0;
//	printf("First\tDistance: %f\tIdx: %d\tAngle: %f\n", distance[idx], idx, angle);
//	printf("Second\tDistance: %f\tIdx: %d\tAngle: %f\tCos angle: %f\n", distance[idx], idx, angle, cos_angle);
//	angle = 355.00;
//	distance[idx] = bigger_distance(cube, r, angle);
//	printf("Angle: %f\tDistance: %f\n", angle, distance[idx]);
	printf("Angle value: %f\n", cube->angle);
	printf("Angle before: %f\tDiff: %f\n", angle, diff);
	while (!double_equals(diff, 0.00) && angle < 359.9999)
	{
		distance[idx] = bigger_distance(cube, r, angle);
		distance[idx] *= cos(cos_angle * cube->rad_const); //TODO: Cuidado cuando el angulo es negativo
		angle += 60.00 / 1200.00;
		cos_angle -= 60.00 / 1200.00;
		idx--;
	}
	if (!double_equals(diff, 0.00))
		angle = 0.00;
	printf("Angle now: %f\n", angle);
	while ((double_equals(diff, 0.00) && !double_equals(cube->angle, 330.00) && angle < cube->angle + 30.00)
			|| (double_equals(diff, 0.00) && double_equals(cube->angle, 330.00) && !double_equals(angle, 0.00))
			|| (!double_equals(diff, 0.00) && cube->angle < 30.00 && angle < 60.00 - diff)
			|| (!double_equals(diff, 0.00) && cube->angle > 30.00 && angle < diff))
	{
		distance[idx] = bigger_distance(cube, r, angle);
		distance[idx] *= cos(cos_angle * cube->rad_const); //TODO: Cuidado cuando el angulo es negativo
		angle += 60.00 / 1200.00;
		cos_angle -= 60.00 / 1200.00;
		if (angle > 359.9999)
			angle = 0.0;
		idx--;
	}
	printf("Angle after: %f\tIdx: %d\n", angle, idx);
	print_screen(cube, distance);
}
