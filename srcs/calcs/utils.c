/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:04:49 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 17:30:07 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	set_segments(t_rays *r, float small_val, float long_val)
{
	r->small_seg = small_val;
	r->long_seg = long_val;
	return (1);
}

void	segment_values(t_cube *cube, t_rays *r, float angle, int mode)
{
	r->incr = 1;
	r->offset = 1;
	if (((angle == 0.00 || (angle > 0.00 && angle < 180.00)) && !mode)
		|| ((angle == 90.00 || (angle > 90.00 && angle < 270.00)) && mode))
	{
		r->incr = -1;
		r->offset = -1;
	}
	if (angle == 0.00 || angle == 180.00)
	{
		((!mode) && (set_segments(r, 50000.00, 100000.00)));
		((mode) && (set_segments(r, 0.00, 0.00)));
	}
	else if (angle == 90.00 || angle == 270.00)
	{
		((!mode) && (set_segments(r, 0.00, 0.00)));
		((mode) && (set_segments(r, 50000.00, 100000.00)));
	}
	else
	{
		((!mode) && (set_segments(r, calc_small(cube, cube->npos_y, angle * \
			cube->rad_const, 0), 64.0 / tan(angle * cube->rad_const))));
		((mode) && (set_segments(r, calc_small(cube, cube->npos_x, angle * \
			cube->rad_const, 1), 64.0 * tan(angle * cube->rad_const))));
	}
}

void	take_direction(t_cube *cube, t_rays *r, t_angle *vals)
{
	if (r->dist_x <= r->dist_y)
	{
		if (vals->angle > 0.00 && vals->angle < 180.00)
			cube->walls.dir[vals->idx] = NO;
		else
			cube->walls.dir[vals->idx] = SO;
		if (vals->angle == 90.00 || vals->angle == 270.00)
			cube->walls.pos[vals->idx] = r->start_x;
		else
			cube->walls.pos[vals->idx] = r->p_x;
	}
	else
	{
		if (vals->angle > 90.00 && vals->angle < 270.00)
			cube->walls.dir[vals->idx] = WE;
		else
			cube->walls.dir[vals->idx] = EA;
		if (vals->angle == 0.00 || vals->angle == 180.00)
			cube->walls.pos[vals->idx] = r->start_y;
		else
			cube->walls.pos[vals->idx] = r->p_y;
	}
}

void	loop(t_cube *cube, t_rays *r, t_point *p, int mod)
{
	while (((!mod && p->x >= 0) || (mod && p->y >= 0)) && p->x < cube->rows
		&& p->y < p->len && cube->map[p->x][p->y] != '1'
		&& cube->map[p->x][p->y] != ' ')
	{
		if (r->incr > 0)
			p->new_val -= r->long_seg;
		else
			p->new_val += r->long_seg;
		r->offset += r->incr;
		if (!mod)
		{
			p->x = (int)fabs(cube->npos_y / 64.00) + r->offset;
			p->y = (int)fabs(p->new_val / 64.00);
			if (p->x >= cube->rows)
				break ;
		}
		else
		{
			p->x = (int)fabs(p->new_val / 64.00);
			p->y = (int)fabs(cube->npos_x / 64.00) + r->offset;
			if (p->x >= cube->rows)
				break ;
		}
		p->len = (int)ft_strlen(cube->map[p->x]);
	}
}

float	loop_point(t_cube *cube, t_rays *r, int mod)
{
	t_point	p;

	if (!mod)
	{
		p.x = (int)(fabs(cube->npos_y / 64.00)) + r->offset;
		p.y = (int)(fabs(r->p_x / 64.00));
		p.new_val = r->p_x;
	}
	else
	{
		p.x = (int)(fabs(r->p_y / 64.00));
		p.y = (int)(fabs(cube->npos_x / 64.00)) + r->offset;
		p.new_val = r->p_y;
	}
	if (p.x >= cube->rows)
		return (p.new_val);
	p.len = (int)ft_strlen(cube->map[p.x]);
	loop(cube, r, &p, mod);
	return (p.new_val);
}
