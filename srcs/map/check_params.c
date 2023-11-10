/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:20:22 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/10 20:12:37 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "libft.h"
#include <fcntl.h>

//	TODO

// Comprobar NO,SO,WE,EA,F,C este
// Comprobar que la ruta sea correcta y este la textura
// Leer el mapa y todal de filas sera el Primer Puntero
// Leer el mapa, la fila mas larga sera el total del Doble puntero

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

void init_texture(char **params, char **textures)
{
	if (!ft_strncmp(params[0], "NO", 2))
		textures[NO] = ft_strdup(params[1]);
	else if (!ft_strncmp(params[0], "SO", 2))
		textures[SO] = ft_strdup(params[1]);
	else if (!ft_strncmp(params[0], "WE", 2))
		textures[WE] = ft_strdup(params[1]);
	else if (!ft_strncmp(params[0], "EA", 2))
		textures[EA] = ft_strdup(params[1]);
}

int check_params(t_cube *cube, char *file)
{
	char **data;
	char **split;
	int i;

	(void)cube;
	(void)split;
	(void)i;
	data = ft_file_to_dptr(file, 1);
	// if (!(cube->params.textures = ft_calloc(sizeof(char *), 5)) || !data || init_map(cube, data))
	if (!(cube->params.textures = ft_calloc(sizeof(char *), 5)) || !data)
		return (EXIT_FAILURE);
	init_map(cube, data);
	// i = 0;
	// if (data)
	// {
	// 	while (data[i])
	// 	{
	// 		split = ft_split(data[i], ' ');
	// 		init_texture(split, cube->params.textures);
	// 		if (!ft_strncmp(split[0], "C", 1))
	// 			init_color(&cube->params.colors[C], split[1]);
	// 		else if (!ft_strncmp(split[0], "F", 1))
	// 			init_color(&cube->params.colors[F], split[1]);
	// 		free(split);
	// 		i++;
	// 	}
	// }
	// cube->params.textures[4] = NULL;
	ft_printf("\tAKI\n");
	// free(data);
	ft_free_dptr(data);
	return (0);
}
