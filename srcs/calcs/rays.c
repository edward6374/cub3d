/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/09 19:52:10 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	check_segments(t_cube *cube, t_rays *r, float angle, int mode)
{
	segment_values(cube, r, angle, mode);
	if (!mode)
	{
		if (angle == 0.00 || (angle > 0.00 && angle < 180.00))
			r->p_x = r->start_x + r->small_seg;
		else
			r->p_x = r->start_x - r->small_seg;
	}
	else
	{
		if (angle == 90.00 || (angle > 90.00 && angle < 270.00))
			r->p_y = r->start_y + r->small_seg;
		else
			r->p_y = r->start_y - r->small_seg;
	}
}

float	bigger_distance(t_cube *cube, t_rays *r, float angle)
{
	check_segments(cube, r, angle, 0);
	r->p_x = loop_point(cube, r, 0);
	if (angle == 90.00)
		r->offset += 1;
	if (angle == 90.00 || angle == 270.00)
	{
		r->p_x = (float)((int)(fabs(cube->nposY / 64.00)) + r->offset) *64.00;
		r->dist_x = fabs((r->start_y - r->p_x) / sin(angle * cube->rad_const));
	}
	else
		r->dist_x = fabs((r->start_x - r->p_x) / cos(angle * cube->rad_const));
	check_segments(cube, r, angle, 1);
	r->p_y = loop_point(cube, r, 1);
	if (angle == 180.00)
		r->offset += 1;
	if (angle == 0.00 || angle == 180.00)
	{
		r->p_y = (float)((int)(fabs(cube->nposX / 64.00)) + r->offset) *64.00;
		r->dist_y = fabs((r->start_x - r->p_y) / cos(angle * cube->rad_const));
	}
	else
		r->dist_y = fabs((r->start_y - r->p_y) / sin(angle * cube->rad_const));
	if (r->dist_x <= r->dist_y)
		return (r->dist_x);
	return (r->dist_y);
}

int	set_values(t_cube *cube, t_angle *vals, t_rays *r)
{
	r->start_x = cube->nposX;
	r->start_y = cube->nposY;
	vals->diff = 0.00;
	vals->cos_angle = 30.00;
	vals->idx = cube->width - 1;
	if (cube->angle - 30.00 < 0.00)
	{
		vals->diff = 30.00 - cube->angle;
		vals->angle = 360.00 - (30.00 - cube->angle);
	}
	else if (cube->angle + 30.00 > 360.00)
	{
		vals->angle = cube->angle - 30.00;
		vals->diff = 30.00 - (360.00 - cube->angle);
	}
	else
	{
		vals->angle = cube->angle - 30.0;
		return (0);
	}
	return (1);
}

void	before_360(t_cube *cube, t_rays *r, t_angle *vals)
{
	while (vals->diff != 0.00 && vals->angle < 359.9999)
	{
		cube->walls.dist[vals->idx] = bigger_distance(cube, r, vals->angle);
		cube->walls.dist[vals->idx] *= cos(vals->cos_angle * cube->rad_const);
		take_direction(cube, r, vals);
		vals->angle += 60.00 / cube->width;
		vals->cos_angle -= 60.00 / cube->width;
		vals->idx--;
	}
	vals->angle -= 360.00;
}

void	calculate_rays(t_cube *cube)
{
	t_rays	r;
	t_angle	vals;

	if (set_values(cube, &vals, &r))
		before_360(cube, &r, &vals);
	while ((vals.diff == 0.00 && cube->angle != 330.00
			&& vals.angle < cube->angle + 30.00) || (vals.diff == 0.00
			&& cube->angle == 330.00 && vals.angle != 0.00)
		|| (vals.diff != 0.00 && cube->angle < 30.00
			&& vals.angle < 60.00 - vals.diff) || (vals.diff != 0.00
			&& cube->angle > 30.00 && vals.angle < vals.diff))
	{
		cube->walls.dist[vals.idx] = bigger_distance(cube, &r, vals.angle);
		cube->walls.dist[vals.idx] *= cos(vals.cos_angle * cube->rad_const);
		take_direction(cube, &r, &vals);
		vals.angle += 60.00 / cube->width;
		vals.cos_angle -= 60.00 / cube->width;
		if (vals.angle > 359.9999)
			vals.angle = 0.00;
		vals.idx--;
	}
	print_screen(cube, cube->walls.dist);
}
