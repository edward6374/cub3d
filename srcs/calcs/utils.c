/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:04:49 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/01 17:05:35 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	double_equals(double a, double b)
{
    return (fabs(a - b) < 0.001);
}

int	set_segments(t_rays *r, double small_val, double long_val)
{
	r->small_seg = small_val;
	r->long_seg = long_val;
	return (1);
}
