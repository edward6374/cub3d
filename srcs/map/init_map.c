/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:55:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/22 12:55:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	len_row(char **data)
{
	int	i;
	int	row;

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

int	init_map(t_cube *cube, char **data)
{
	int	i;
	int	j;
	int	map_index;

	i = -1;
	map_index = 0;
	cube->map = ft_calloc(len_row(data) + 1, sizeof(char *));
	if (!cube->map)
		return (EXIT_FAILURE);
	while (data[++i])
	{
		if (data[i][0] == ' ' || data[i][0] == '1')
		{
			cube->map[map_index] = ft_calloc(ft_strlen(data[i]) + 1, 1);
			if (!cube->map[map_index])
				return (EXIT_FAILURE);
			j = -1;
			while (data[i][++j] != '\n' && data[i][j] != '\0')
				cube->map[map_index][j] = data[i][j];
			cube->map[map_index][j] = '\0';
			map_index++;
		}
	}
	cube->map[map_index] = NULL;
	return (0);
}
