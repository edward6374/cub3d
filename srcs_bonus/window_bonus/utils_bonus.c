/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:02:04 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 15:18:29 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <math.h>

void	update_pos(t_cube *cube, float *angle_vals, int sum, int idx)
{
	if (!sum)
	{
		cube->npos_x += angle_vals[idx];
		cube->npos_y -= angle_vals[idx + 1];
	}
	else
	{
		cube->npos_x -= angle_vals[idx];
		cube->npos_y += angle_vals[idx + 1];
	}
	if ((int)(cube->npos_x / 64) > cube->i_x)
		cube->i_x++;
	else if ((int)(cube->npos_x / 64) < cube->i_x)
		cube->i_x--;
	if ((int)(cube->npos_y / 64) > cube->i_y)
		cube->i_y++;
	else if ((int)(cube->npos_y / 64) < cube->i_y)
		cube->i_y--;
}

int	direct(float angle, int dir)
{
	if (dir % 2)
	{
		if (dir == 13)
		{
			if (angle == 0.00 || (angle > 0.00 && angle < 90.00))
				return (1);
			else if (angle == 90.00 || (angle > 90.00 && angle < 180.00))
				return (2);
			else if (angle == 180.00 || (angle > 180.00 && angle < 270.00))
				return (3);
			return (4);
		}
		else
		{
			if (angle == 180.00 || (angle > 180.00 && angle < 270.00))
				return (1);
			if (angle == 270.00 || (angle > 270.00 && angle < 360.00))
				return (2);
			if (angle == 0.00 || (angle > 0.00 && angle < 90.00))
				return (3);
			return (4);
		}
	}
	return (0);
}

int	side(float angle, int dir)
{
	if (dir % 2 == 0)
	{
		if (dir == 0)
		{
			if (angle == 270.00 || (angle > 270.00 && angle < 360.00))
				return (1);
			else if (angle == 0.00 || (angle > 0.00 && angle < 90.00))
				return (2);
			else if (angle == 90.00 || (angle > 90.00 && angle < 180.00))
				return (3);
			return (4);
		}
		else
		{
			if (angle == 90.00 || (angle > 90.00 && angle < 180.00))
				return (1);
			else if (angle == 180.00 || (angle > 180.00 && angle < 270.00))
				return (2);
			else if (angle == 270.00 || (angle > 270.00 && angle < 360.00))
				return (3);
			return (4);
		}
	}
	return (0);
}

int	check_mov(t_cube *cube, int *i_out, int *i_xy, int key)
{
	float	angle;

	angle = cube->angle;
	if ((direct(angle, key) == 1 || side(angle, key) == 1)
		&& (cube->map[i_out[NO]][i_xy[0]] == '1'
		|| cube->map[i_xy[1]][i_out[EA]] == '1'))
		return (1);
	else if ((direct(angle, key) == 2 || side(angle, key) == 2)
		&& (cube->map[i_out[NO]][i_xy[0]] == '1'
		|| cube->map[i_xy[1]][i_out[WE]] == '1'))
		return (1);
	else if ((direct(angle, key) == 3 || side(angle, key) == 3)
		&& (cube->map[i_out[SO]][i_xy[0]] == '1'
		|| cube->map[i_xy[1]][i_out[WE]] == '1'))
		return (1);
	else if ((direct(angle, key) == 4 || side(angle, key) == 4)
		&& (cube->map[i_out[SO]][i_xy[0]] == '1'
		|| cube->map[i_xy[1]][i_out[EA]] == '1'))
		return (1);
	return (0);
}

void	set_idx(t_cube *cube, int *i_out, int *i_xy, float *angle_vals)
{
	float	incr;

	incr = 10.00;
	i_xy[0] = (int)fabs(cube->npos_x / 64.00);
	i_xy[1] = (int)fabs(cube->npos_y / 64.00);
	i_out[NO] = (int)fabs((cube->npos_y - incr) / 64.00);
	i_out[SO] = (int)fabs((cube->npos_y + incr) / 64.00);
	i_out[WE] = (int)fabs((cube->npos_x - incr) / 64.00);
	i_out[EA] = (int)fabs((cube->npos_x + incr) / 64.00);
	angle_vals[COS] = 2.00 * cos(cube->angle * cube->rad_const);
	angle_vals[SIN] = 2.00 * sin(cube->angle * cube->rad_const);
	angle_vals[COS_90] = 2.00 * cos((cube->angle + 90.00) * cube->rad_const);
	angle_vals[SIN_90] = 2.00 * sin((cube->angle + 90.00) * cube->rad_const);
}
