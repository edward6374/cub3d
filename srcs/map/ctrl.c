/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:05:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/11 13:40:12 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"

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

int ctrl_player(t_cube *cube, char **map)
{
	int i;
	int j;

	// int x;
	// int y;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			// ft_printf("%c", map[i][j]);
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
				map[i][j] == 'W')
			{
				cube->iX = j;
				cube->iY = i;
				// x = j;
				// y = i;
				// ft_printf(RED "\ni:%d, j:%d\n" RESET, i, j);
			}
			j++;
		}
		i++;
	}
	// printf(MAGENTA "Pos X: %d\tPos Y: %d\n" RESET, x, y);

	cube->nposX = (double)((cube->iX * 64) + 32);
	cube->nposY = (double)((cube->iY * 64) + 32);

	printf(GREEN "X: %d\tY: %d\tPos X: %f\tPos Y: %f\n" RESET, cube->iX, cube->iY, cube->nposX, cube->nposY);

	return (0);
}
