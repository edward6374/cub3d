/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:55:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/08 22:09:42 by nmota-bu         ###   ########.fr       */
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
	char **map;
	int i;
	int map_index;
	int j;

	if (!(map = malloc(len_row(data) * sizeof(char *))))
		return (EXIT_FAILURE);
	i = 0;
	map_index = 0;
	while (data[i])
	{
		if (data[i][0] == ' ' || data[i][0] == '1')
		{
			if (!(map[map_index] = malloc(strlen(data[i]) + 1)))
				return (EXIT_FAILURE);
			j = 0;
			while (data[i][j] != '\n')
			{
				map[map_index][j] = data[i][j];
				j++;
			}
			map[map_index][j] = '\0';
			map_index++;
		}
		i++;
	}
	map[map_index] = NULL;
	cube->map = map;
	return (0);
}
