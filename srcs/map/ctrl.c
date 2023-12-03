/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:05:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/03 22:52:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

void check_img(char *file)
{
	if (!ft_strnstr(&file[ft_strlen(file) - 4], ".xpm", 4))
	{
		ft_message(DANGER, "Eror\nWrong path or file: "), ft_message(INFO,
																	 file);
		exit(EXIT_FAILURE);
	}
}

int ctrl_path(t_img img[])
{
	int i;
	int fd;
	int err;

	i = -1;
	err = 0;
	while (img[++i].path)
	{
		fd = open(img[i].path, O_RDONLY);
		if (fd >= 0)
		{
			check_img(img[i].path);
			close(fd);
		}
		else if (fd <= 0)
		{
			err = 1;
			ft_message(DANGER, "Error\nWrong path: ");
			ft_message(INFO, img[i].path);
		}
	}
	return (err);
}

void ctrl_char(char ch, double *angle)
{
	if (ch != 'N' && ch != 'S' && ch != 'E' && ch != 'W' && ch != '1' && ch != '0' && ch != ' ')
	{
		ft_message(DANGER, "Error");
		ft_printf(CYAN "The character: '%c' cannot be on the map\n" RESET, ch);
		exit(EXIT_FAILURE);
	}
	if (ch == 'N')
		*angle = 90.00;
	else if (ch == 'S')
		*angle = 270.00;
	else if (ch == 'E')
		*angle = 0.00;
	else if (ch == 'W')
		*angle = 180.00;
}

int ctrl_player(t_cube *cube, char **map)
{
	int i;
	int j;
	int err;

	err = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ctrl_char(map[i][j], &cube->angle);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'W')
			{
				if (err == 1)
				{
					ft_message(DANGER,
							   "Error\n"
							   "There can only be one N, S, E,W");
					return (EXIT_FAILURE);
				}
				err = 1;
				cube->iX = j;
				cube->iY = i;
			}
			j++;
		}
		i++;
	}
	if (err == 0)
	{
		ft_message(DANGER, "Error\nMissing N, S, E, W");
		return (EXIT_FAILURE);
	}
	cube->nposX = (double)((cube->iX * 64) + 32);
	cube->nposY = (double)((cube->iY * 64) + 32);
	return (0);
}

int check_map_format(char **map, int rows)
{
	int i = -1;
	while (map[++i])
	{
		int j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("0NSWE", map[i][j]))
			{
				if (i == 0 || i == rows - 1 || j == 0 || j == (int)ft_strlen(map[i]) - 1)
				{
					ft_message(DANGER, "Error\n'0' cannot be in the perimeter.");
					return (1);
				}
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
					map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || (map[i][j] == '0' && map[i - 1][j] == '\0'))
				{
					{
						ft_message(DANGER, "Error\nThe map is not closed.");
						return (1);
					}
				}
			}
		}
	}
	return (0);
}

int ctrl_map(t_cube *cube)
{
	int rows;

	rows = 0;
	while (cube->map[rows])
		rows++;
	return (check_map_format(cube->map, rows));
}
