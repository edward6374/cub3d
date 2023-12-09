/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:09:32 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/09 19:56:47 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs.h"
#include <math.h>

float	calc_small(t_cube *cube, float pos, float angle, int mode)
{
	float	diff_x;
	float	diff_y;
	float	tan_value;
	float	just_angle;

	tan_value = tan(angle);
	just_angle = angle / cube->rad_const;
	diff_x = ((cube->iY + 1) * 64.00) - pos;
	diff_y = ((cube->iX + 1) * 64.00) - pos;
	if (!mode)
	{
		if (just_angle == 0.00 || just_angle == 180.00
			|| (just_angle > 0.00 && just_angle < 180.00))
			return (fmod(cube->nposY, 64.00) / tan_value);
		return (diff_x / tan_value);
	}
	else
	{
		if (just_angle == 90.00 || just_angle == 270.00
			|| (just_angle > 90.00 && just_angle < 270.00))
			return (fmod(cube->nposX, 64.00) * tan_value);
		return (diff_y * tan_value);
	}
}

void	print_pixel(t_cube *cube, int x, int y, t_color colors)
{
	my_mlx_pixel_put(&cube->mlx, x, y, ((0 & 0xff) << 24) + \
		((colors.r & 0xff) << 16) + ((colors.g & 0xff) << 8) + \
		((colors.b & 0xff)));
}

int	check_x(t_cube *cube, int idx)
{
	int		ret;
	float	min;
	float	max;
	float	diff;
	float	piece;

	diff = fmodf(cube->walls.pos[idx], 64.00);
	min = cube->walls.pos[idx] - diff;
	max = min + 64.00;
	piece = (max - min) / 5.00;
	ret = (int)round(((fmodf(cube->walls.pos[idx] - min, piece) \
		* 64.00) / piece));
	if (ret == 64)
		ret = 0;
	return (ret);
}

void	print_image(t_cube *cube, float height, int x, int y)
{
	int		idx;
	float	min;
	float	piece;
	char	*find;
	t_color	*rgb;

	min = (((float)cube->height / 2.00) - height);
	piece = ((((float)cube->height / 2.00) + height) - min) / 5.00;
	idx = (int)round(((fmodf((float)y - min, piece) * 64.00) / piece));
	if (idx == 64)
		idx = 0;
	find = find_char(&cube->img[cube->walls.dir[x]], idx, check_x(cube, x));
	rgb = find_rgb(cube->img[cube->walls.dir[x]].lst, find, \
		cube->img->measures[CHAR]);
	print_pixel(cube, x, y, *rgb);
	free(find);
}

void	print_screen(t_cube *cube, float *arr)
{
	int		x;
	int		y;
	float	height;

	x = -1;
	while (++x < cube->width)
	{
		y = -1;
		height = ((64.00 / arr[x]) * cube->length_ray) / 2.00;
		while (++y < cube->height)
		{
			if ((float)y > (float)(cube->height / 2.00) - height
				&& (float)y < (float)(cube->height / 2.00) + height)
				print_image(cube, height, x, y);
			else if ((float)y < (float)(cube->height / 2.00) - height)
				print_pixel(cube, x, y, cube->params.colors[C]);
			else
				print_pixel(cube, x, y, cube->params.colors[F]);
		}
	}
}
