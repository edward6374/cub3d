/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:20:22 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/22 16:04:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>

#include "colorsft.h"

void check_rgb(int r, int g, int b)
{
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
	{
		ft_message(DANGER, "Error\nThe color is not within RBG.");
		exit(EXIT_FAILURE);
	}
}

void init_color(t_color *color, char *split)
{
	char **rgb;
	int r;
	int g;
	int b;

	rgb = ft_split(split, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	check_rgb(r, g, b);
	color->r = r;
	color->g = g;
	color->b = b;
	free(rgb);
}

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

void init_texture(char **params, char **path)
{
	if (!ft_strncmp(params[0], "NO", 2))
		path[NO] = ft_strdup_plus(params[1]);
	else if (!ft_strncmp(params[0], "SO", 2))
		path[SO] = ft_strdup_plus(params[1]);
	else if (!ft_strncmp(params[0], "WE", 2))
		path[WE] = ft_strdup_plus(params[1]);
	else if (!ft_strncmp(params[0], "EA", 2))
		path[EA] = ft_strdup_plus(params[1]);
}

int check_params(t_cube *cube, char *file)
{
	char **data;
	char **split;
	int i;

	data = ft_file_to_dptr(file, 1);
	if (!(cube->params.path = ft_calloc(sizeof(char *), 5)) || !data || init_map(cube, data))
		exit(EXIT_FAILURE);
	// check_path_img();

	// TODO
	// hacer strjoin con C F

	i = 0;
	if (data)
	{
		while (data[i])
		{
			split = ft_split(data[i], ' ');
			// int j = 0;
			// while (split[j])
			// {

			// 	printf(CYAN "%d:%s\n" RESET, j, split[j]);
			// 	j++;
			// }
			init_texture(split, cube->params.path);
			if (!ft_strncmp(split[0], "C", 1))
				init_color(&cube->params.colors[C], split[1]);
			else if (!ft_strncmp(split[0], "F", 1))
				init_color(&cube->params.colors[F], split[1]);
			ft_free_dptr(split);
			i++;
		}
	}
	cube->params.path[4] = NULL;
	ft_free_dptr(data);
	return (0);
}
