/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:04:49 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/28 19:17:58 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	print_pixel(t_cube *cube, int x, int y, t_color colors)
{
	my_mlx_pixel_put(&cube->mlx, x, y, ((0 & 0xff) << 24) + \
	   ((colors.r & 0xff) << 16) + ((colors.g & 0xff) << 8) + \
	   ((colors.b & 0xff)));
}

int	dbl_eq(double a, double b)
{
    return (fabs(a - b) < 0.001);
}

int	dbl_btw(double angle, double min, double max)
{
	if (angle > min && angle < max)
		return (1);
    return (0);
}

int	set_segments(t_rays *r, double small_val, double long_val)
{
	r->small_seg = small_val;
	r->long_seg = long_val;
	return (1);
}
