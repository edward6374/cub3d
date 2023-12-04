/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:08:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/04 09:13:18 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "libft.h"

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
