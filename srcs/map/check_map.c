/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:20:22 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/07 14:40:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

//	TODO
//	Comprobar la extension del fichero .cub

// map tiene que tener la extension cub

// Comprobar NO,SO,WE,EA,F,C este
// Comprobar que la ruta sea correcta y este la textura
// comprobar que sea un valor valido para RGB entre 0 y 255
// Leer el mapa y todal de filas sera el Primer Puntero
// Leer el mapa, la fila mas larga sera el total del Doble puntero

int check_map(t_cube *cube, char *str)
{
	// char **file;
	// file = ft_file_to_dptr(argv[1],0); // free(file)

	(void)str;
	(void)cube;
	// map = open(str, O_RDONLY);
	// if (map == -1)
	// return (1);
	return (0);
}

// TODO
