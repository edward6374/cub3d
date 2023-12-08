/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:04:49 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/08 12:10:48 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

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

int	set_segments(t_rays *r, float small_val, float long_val)
{
	r->small_seg = small_val;
	r->long_seg = long_val;
	return (1);
}
