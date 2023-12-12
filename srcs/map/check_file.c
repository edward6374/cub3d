/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:08:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/12 12:10:38 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "libft.h"

int	check_player_error(t_cube *cube, int *err, int i, int j)
{
	if (*err == 1)
		return (ft_message(DANGER, "Error\n"
				"There can only be one N, S, E, W"), EXIT_FAILURE);
	*err = 1;
	cube->i_x = j;
	cube->i_y = i;
	return (0);
}

void	check_img(char *file)
{
	if (!ft_strnstr(&file[ft_strlen(file) - 4], ".xpm", 4))
	{
		ft_message(DANGER, "Eror\nWrong path or file: ");
		ft_message(INFO, file);
		exit(EXIT_FAILURE);
	}
}

int	check_file(int argc, char *file)
{
	if (argc == 1)
		return (ft_message(DANGER, "Error\nMap file name required."),
			EXIT_FAILURE);
	else if (argc > 2)
		return (ft_message(DANGER, "Error\nToo many arguments."), EXIT_FAILURE);
	else
	{
		if (!ft_strnstr(&file[ft_strlen(file) - 4], ".cub", 4))
			return (ft_message(DANGER,
					"Error\nFile map does not have the extension .cub"),
				EXIT_FAILURE);
	}
	return (0);
}
