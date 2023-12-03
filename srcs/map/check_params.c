/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:20:22 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/03 22:52:21 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>

#include "colorsft.h"

char *ft_strdup_plus(char *s1)
{
	int i;
	char *ptr;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		if (s1[i] != '\n')
			ptr[i] = s1[i];
		else if (s1[i] == '\n')
			break;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void init_texture(char **split, t_img *img)
{
	if (!ft_strncmp(split[0], "NO", 2))
		img[NO].path = ft_strdup_plus(split[1]);
	else if (!ft_strncmp(split[0], "SO", 2))
		img[SO].path = ft_strdup_plus(split[1]);
	else if (!ft_strncmp(split[0], "WE", 2))
		img[WE].path = ft_strdup_plus(split[1]);
	else if (!ft_strncmp(split[0], "EA", 2))
		img[EA].path = ft_strdup_plus(split[1]);
}

int check_params(t_cube *cube, char *file)
{
	char **data;
	char **split;
	int i;

	data = ft_file_to_dptr(file, 1);
	if (!data || init_map(cube, data))
		exit(EXIT_FAILURE);
	i = 0;
	if (data)
	{
		while (data[i])
		{
			split = ft_split(data[i], ' ');
			init_texture(split, cube->img);
			if (!ft_strncmp(split[0], "C", 1))
				check_rgb(&cube->params.colors[C], split);
			else if (!ft_strncmp(split[0], "F", 1))
				check_rgb(&cube->params.colors[F], split);
			ft_free_dptr(split);
			i++;
		}
	}
	ft_free_dptr(data);
	return (0);
}
