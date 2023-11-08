/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:20:22 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/08 16:27:43 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

//	TODO

// Comprobar NO,SO,WE,EA,F,C este
// Comprobar que la ruta sea correcta y este la textura
// comprobar que sea un valor valido para RGB entre 0 y 255
// Leer el mapa y todal de filas sera el Primer Puntero
// Leer el mapa, la fila mas larga sera el total del Doble puntero

void init_color(t_color *color, char *split)
{
	char **rgb;

	rgb = ft_split(split, ',');
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free(rgb);
}

int init_texture(char **params, char **textures)
{
	// textures = malloc(sizeof(char *) * 5);
	// // return (EXIT_FAILURE);
	if (!ft_strncmp(params[0], "NO", 2))
		textures[NO] = ft_strdup(params[1]);
	else if (!ft_strncmp(params[0], "SO", 2))
		textures[SO] = ft_strdup(params[1]);
	else if (!ft_strncmp(params[0], "WE", 2))
		textures[WE] = ft_strdup(params[1]);
	else if (!ft_strncmp(params[0], "EA", 2))
		textures[EA] = ft_strdup(params[1]);

	return (0);
}

int check_params(t_cube *cube, char *file)
{
	char **data;
	char **split;
	int err;

	err = 0;

	data = ft_file_to_dptr(file, 1);
	if (!(cube->params.textures = malloc(sizeof(char *) * 5)) || !data)
		return (EXIT_FAILURE);
	int i = 0;
	if (data)
	{
		while (data[i])
		{
			split = ft_split(data[i], ' ');

			init_texture(split, cube->params.textures);

			// if (!ft_strncmp(split[0], "NO", 2))
			// 	cube->params.textures[NO] =t_strdup(split[1]);
			// else if (!ft_strncmp(split[0], "SO", 2))
			// 	cube->params.textures[SO] = ft_strdup(split[1]);
			// else if (!ft_strncmp(split[0], "WE", 2))
			// 	cube->params.textures[WE] = ft_strdup(split[1]);
			// else if (!ft_strncmp(split[0], "EA", 2))
			// 	cube->params.textures[EA] = ft_strdup(split[1]);
			if (!ft_strncmp(split[0], "C", 1))
				// else if (!ft_strncmp(split[0], "C", 1))
				init_color(&cube->params.colors[C], split[1]);
			else if (!ft_strncmp(split[0], "F", 1))
				init_color(&cube->params.colors[F], split[1]);
			free(split);
			i++;
		}
	}
	cube->params.textures[4] = NULL;
	free(data);

	// i = 0;
	// while (cube->params.textures[i])
	// {

	// 	ft_printf("%s\n", cube->params.textures[i]);
	// 	i++;
	// }
	return (err);
}
