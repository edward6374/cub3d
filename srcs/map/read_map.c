/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:35 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/31 09:35:51 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fill_borders(t_cube *cube)
{
	int i;
	int j;

	i = -1;
	while (++i < cube->width)
	{
		j = -1;
		while (++j < cube->height)
		{
			if ((i > 120 && i < 1120) && j == 121)
				j = 1119;
			else
				my_mlx_pixel_put(&cube->mlx, i, j, 0x99FFCC);
		}
	}
	// mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
}

void read_map(t_cube *cube)
{
	int i;
	int j;
	int l;
	int str_l;
	int str_c;
	int last_i;
	int last_j;
	int max_length;

	i = -1;
	max_length = -1;
	while (cube->map[++i])
		if ((int)ft_strlen(cube->map[i]) > max_length)
			max_length = ft_strlen(cube->map[i]);
	fill_borders(cube);
	l = (cube->width - 240) / max_length;
	i = 120;
	j = 120;
	last_i = i + l;
	last_j = j + l;
	str_l = 0;
	str_c = 0;
	// printf("Before loop\n");
	while (42)
	{
		while (++i < last_i)
		{
			j = last_j - l;
			// printf("Before while\tI: %d\tJ: %d\n", i, j);
			while (++j < last_j)
			{
				if (cube->map[str_l][str_c] == '0')
					my_mlx_pixel_put(&cube->mlx, i, j, 0xFFFFFF);
				else if (cube->map[str_l][str_c] == '1')
					my_mlx_pixel_put(&cube->mlx, i, j, 0x0000FF);
				else if (cube->map[str_l][str_c] == 'N')
					my_mlx_pixel_put(&cube->mlx, i, j, 0xFF0000);
			}
		}
		// printf("End\tI: %d\tJ: %d\tN: %d\tC: %d\n", i, j, str_l, str_c);
		if (i < 1120)
		{
			last_i += l;
			str_c++;
		}
		else if (i == 1120 && j == 1120)
			break;
		else if (i == 1120)
		{
			i = 120;
			j = last_j;
			last_i = i + l;
			last_j += l;
			str_c = 0;
			str_l++;
			// printf("I: %d\tJ: %d\tLast i: %d\tLast j: %d\n", i, j, last_i, last_j);
			// return;
		}
		// printf("Str n: %d\tStr c:%d\n", str_l, str_c);
	}
	// printf("I: %d\tJ: %d\n", i, j);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
}
