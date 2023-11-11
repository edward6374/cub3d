/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:55:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/10 22:49:30 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int len_row(char **data)
{
	int i;
	int row;

	i = 0;
	row = 0;
	while (data[i])
	{
		if (data[i][0] == ' ' || data[i][0] == '1')
			row++;
		i++;
	}
	return (row);
}

int init_map(t_cube *cube, char **data)
{
	int i;
	int map_index;
	int j;

	if (!(cube->map = ft_calloc(len_row(data) + 1, sizeof(char *))))
		return (EXIT_FAILURE);
	i = 0;
	map_index = 0;
	while (data[i])
	{
		if (data[i][0] == ' ' || data[i][0] == '1')
		{
			if (!(cube->map[map_index] = ft_calloc(strlen(data[i]) + 1, 1)))
				return (EXIT_FAILURE);
			j = 0;
			while (data[i][j] != '\0')
			{
				if (data[i][j] != '\n')
					cube->map[map_index][j] = data[i][j];
				j++;
			}
			cube->map[map_index][j] = '\0';
			map_index++;
		}
		i++;
	}
	cube->map[map_index] = NULL;
	return (0);
}
