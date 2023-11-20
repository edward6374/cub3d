/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:18:35 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/20 18:32:02 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	fill_borders(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cube->width)
	{
		j = -1;
		while (++j < cube->height)
		{
			if ((i > 120 && i < 1080) && j == 121)
				j = 1079;
			else
				my_mlx_pixel_put(&cube->mlx, i, j, 0x99FFCC);
		}
	}
}

void	map_person_point(t_cube *cube, int dir)
{
	int	x;
	int	y;

	x = -3;
	y = -3;
	while (++x < 3)
	{
		y = -3;
		while (++y < 3)
			my_mlx_pixel_put(&cube->mlx, cube->posX + x, cube->posY + y,
				0x000000);
	}
	// Limpiar mapa
	if (dir == 0)
	{
		my_mlx_pixel_put(&cube->mlx, cube->posX, cube->posY + 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 1, cube->posY + 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 2, cube->posY + 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 1, cube->posY + 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 2, cube->posY + 3, 0xFFFFFF);
	}
	else if (dir == 1)
	{
		my_mlx_pixel_put(&cube->mlx, cube->posX, cube->posY - 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 1, cube->posY - 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 2, cube->posY - 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 1, cube->posY - 3, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 2, cube->posY - 3, 0xFFFFFF);
	}
	else if (dir == 2)
	{
		my_mlx_pixel_put(&cube->mlx, cube->posX - 3, cube->posY, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 3, cube->posY + 1, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 3, cube->posY + 2, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 3, cube->posY - 1, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX - 3, cube->posY - 2, 0xFFFFFF);
		// my_mlx_pixel_put(&cube->mlx, cube->posX - 3, cube->posY - 3,
		// 0xFFFFFF);
	}
	else
	{
		my_mlx_pixel_put(&cube->mlx, cube->posX + 3, cube->posY, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 3, cube->posY + 1, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 3, cube->posY + 2, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 3, cube->posY - 1, 0xFFFFFF);
		my_mlx_pixel_put(&cube->mlx, cube->posX + 3, cube->posY - 2, 0xFFFFFF);
		// my_mlx_pixel_put(&cube->mlx, cube->posX + 3, cube->posY + 3,
		// 0xFFFFFF);
	}
//	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
}

void	read_map(t_cube *cube)
{
	int	i;
	int	j;
	int	l;
	int	str_l;
	int	str_c;
	int	last_i;
	int	last_j;
	int	max_length;

	i = -1;
	max_length = -1;
	while (cube->map[++i])
		if ((int)ft_strlen(cube->map[i]) > max_length)
			max_length = ft_strlen(cube->map[i]);
	fill_borders(cube);
	l = (cube->width - 240) / max_length;
//	printf("l: %d\tMax: %d\tWidth: %d\n", l, max_length, cube->width);
	i = 119;
	j = 119;
	last_i = i + l + 1;
	last_j = j + l + 1;
//	printf("Last i:%d\tLast j:%d\n", last_i, last_j);
	str_l = 0;
	str_c = 0;
	while (i < 1080 || j < 1080)
	{
//		printf("START: %d\t%d\n", i, j);
		while (++i < last_i)
		{
			j = last_j - l;
//			printf("BEGIN: %d\t%d\n", i, j);
			while (++j < last_j)
			{
//				printf("LOOP: %d\t%d\t%d\t%d\n", i, j, str_l, str_c);
				if (cube->map[str_l][str_c] == '0' || cube->map[str_l][str_c] == 'N')
					my_mlx_pixel_put(&cube->mlx, i, j, 0xFFFFFF);
				else if (cube->map[str_l][str_c] == '1')
					my_mlx_pixel_put(&cube->mlx, i, j, 0x0000FF);
				if (cube->map[str_l][str_c] == 'N' && cube->posX == 0)
				{
					cube->posX = last_i - (l / 2);
					cube->posY = last_j - (l / 2);
				}
			}
//			printf("NOW: %d\t%d\n", i, j);
		}
//		printf("I: %d\tJ: %d\n", i, j);
//		if (i >= 1080 && j > 500)
//			break;
		if (i >= 1080 && j < 1080)
		{
			i = 119;
			str_c = 0;
			str_l++;
			last_j += l;
			last_i = i + l + 1;
			j = last_j - l;
		}
		else
		{
//			i--;
			last_i += l;
			str_c++;
		}
	}
	map_person_point(cube, -1);
	printf("PosX: %d\tPosY: %d\n", cube->posX, cube->posY);
//	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
}
*/
