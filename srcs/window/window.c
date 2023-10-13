/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:44:39 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/10 15:29:27 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	map_max_len(t_cube *cube, int mode)
{
	int	i;
	int	max;

	max = -1;
	if (!mode)
	{
		i = -1;
		while (cube->map[++i])
			if ((int)ft_strlen(cube->map[i]) > max)
				max = ft_strlen(cube->map[i]);
		return (max);
	}
	else
	{
		i = 0;
		while (cube->map[i])
			i++;
		return (i);
	}
}

void	print_minimap(t_cube *cube, int max_x, int max_y, int offset)
{
	int	i;
	int	j;
	int	l;
	int	str_l;
	int	str_c;
	int	last_i;
	int	last_j;
	int	max_length;
	int	max_width;

	max_length = map_max_len(cube, 0);
	max_width = map_max_len(cube, 1);
	l = 6;
	i = (max_x / 2) - ((max_length * l) / 2) + offset;
	j = (max_y / 2) - ((max_width * l) / 2) + offset;
	last_i = i + l;
	last_j = j + l;
	str_l = 0;
	str_c = 0;
	while (42)
	{
		while (i < last_i)
		{
			j = last_j - l;
			while (j < last_j)
			{
				if (cube->map[str_l][str_c] == '0')
					my_mlx_pixel_put(&cube->mlx, i, j, 0xFFFFFF);
				else if (cube->map[str_l][str_c] == '1')
					my_mlx_pixel_put(&cube->mlx, i, j, 0x0000FF);
				else if (cube->map[str_l][str_c] == 'N')
				{
					cube->posX = last_i - (l / 2);
					cube->posY = last_j - (l / 2);
					my_mlx_pixel_put(&cube->mlx, i, j, 0xFFFFFF);
				}
				j++;
			}
			i++;
		}
		if (i < ((max_x / 2) + ((max_length * l) / 2) + offset))
		{
			last_i += l;
			str_c++;
		}
		else if (i == ((max_x / 2) + ((max_length * l) / 2) + offset)
			&& j == ((max_y / 2) + ((max_width * l) / 2) + offset))
			break ;
		else if (i == ((max_x / 2) + ((max_length * l) / 2) + offset))
		{
			i = (max_x / 2) - ((max_length * l) / 2) + offset;
			// j = last_j;
			last_i = i + l;
			last_j += l;
			str_c = 0;
			str_l++;
		}
	}
	map_person_point(cube, -1);
}

void	create_minimap(t_cube *cube)
{
	int	i;
	int	j;
	int	max_x;
	int	max_y;
	int	offset;

	offset = 20;
	i = offset - 1;
	max_x = 240;
	max_y = 120;
	while (++i < max_x + offset)
	{
		j = offset - 1;
		while (++j < max_y + offset)
		{
			my_mlx_pixel_put(&cube->mlx, i, j, 0x99FFCC);
		}
	}
	print_minimap(cube, max_x, max_y, offset);
}

void	hook_mlx(t_cube *cube)
{
	read_map(cube);
//	create_minimap(cube);
	cube->mlx.status = 0;
//	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
	mlx_key_hook(cube->mlx.win, key_hook, cube);
	mlx_mouse_hook(cube->mlx.win, mouse_hook, cube);
	mlx_hook(cube->mlx.win, 17, 0, exit_safe, cube);
	mlx_hook(cube->mlx.win, 2, 1L << 0, keep_pressed, cube);
	mlx_loop_hook(cube->mlx.mlx, loop_hook, cube);
	mlx_loop(cube->mlx.mlx);
}

int	init_mlx(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	if (!cube->mlx.mlx)
		return (1);
	cube->mlx.win = mlx_new_window(cube->mlx.mlx, cube->width, cube->height,
		"cub3d");
	// cube->mlx.win = mlx_new_window(cube->mlx.mlx, 360, 180, "cub3d");
	if (!cube->mlx.win)
		return (2);
	cube->mlx.img = mlx_new_image(cube->mlx.mlx, cube->width, cube->height);
	if (!cube->mlx.img)
		return (3);
	cube->mlx.addr = mlx_get_data_addr(cube->mlx.img, &cube->mlx.bits_per_pixel,
		&cube->mlx.line_length, &cube->mlx.endian);
	if (!cube->mlx.addr)
		return (4);
	hook_mlx(cube);
	return (0);
}
