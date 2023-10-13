/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:41:52 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/13 15:27:31 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	calculate_rays(t_cube *cube)
{
	int	offset;
	int	check;
	double	paX;
	double	paY;
	double	pbX;
	double	pbY;
	double	angle;
	double	startX;
	double	startY;

	angle = 60.0;
	while (angle < 120.0)
	{
		startX = ((double)cube->nposX * 64) + 32.0; //416.00
		startY = ((double)cube->nposY * 64) + 32.0; //416.00
		double	firstXa = 32.0 / tan(60.0 * cube->rad_const); //18.4752086
		double	otherXa = 64.0 / tan(60.0 * cube->rad_const); //36.9504172
		check = false;
		offset = 1;
		paX = startX + firstXa; //434.4752086
		while (!check)
		{
			if (cube->nposY - offset < 0 || cube->map[cube->nposY - offset][(int)fabs(paX / 64)] == '1')
				check = true;
			else
			{
				paX += otherXa;
				offset++;
			}
		}
		paY = (double)(cube->nposY - offset + 1) * 64.0;
		float	distance = sqrt(pow(paX - startX, 2) + pow(paY - startY, 2));
		printf("Distance: %f\n", distance);
		angle += cube->
	}
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
