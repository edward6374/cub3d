/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:05:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/11 15:02:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

int ctrl_path(char **textures)
{
	int i;
	int fd;
	int err;

	i = 0;
	err = 0;
	if (textures)
	{
		while (textures[i])
		{
			fd = open(textures[i], O_RDONLY);
			if (fd >= 0)
				close(fd);
			else if (fd <= 0)
			{
				err = 1;
				ft_message(DANGER, "Eror\nWrong path: ");
				ft_message(INFO, textures[i]);
			}
			i++;
		}
	}
	return (err);
}

// TODO
// control que este N O E W y ponerlo en su sito
// colocar angulo
// n-90
// e 0
// s 270
// w 180

void ctrl_char(char ch, double *angle)
{
	if (ch != 'N' && ch != 'S' && ch != 'E' && ch != 'W' && ch != '1' && ch != '0')
	{
		ft_message(DANGER, "Error");
		ft_printf(CYAN "The character: '%c' cannot be on the map\n" RESET, ch);
		exit(EXIT_FAILURE);
	}
	if (ch == 'N')
		*angle = 90;
	else if (ch == 'S')
		*angle = 200;
	else if (ch == 'E')
		*angle = 0;
	else if (ch == 'W')
		*angle = 180;
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
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
				map[i][j] == 'W')
			{
				if (err == 1)
				{
					ft_message(DANGER, "Error\n"
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
	// TODO
	printf(GREEN "X: %d\tY: %d\tPos X: %f\tPos Y: %f\n" RESET, cube->iX,
		   cube->iY, cube->nposX, cube->nposY);
	printf(GREEN "Angle: %f\n", cube->angle);
	return (0);
}

// TODO
// control que no haya ningun otro char que no sea 1 0 N, S, E, W
