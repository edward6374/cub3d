/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:01 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/30 18:13:15 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d.h"
#include <math.h>

//	TODO
//	Nacho, tienes que hacer el init_func bien, con un archivo da leer

void	init_func(t_cube *cube)
{
	int i;

	i = 0;
	cube->rad_const = M_PI / 180.0;
	cube->width = 1280;
	cube->height = 720;
	cube->posX = cube->nposX;
	cube->posY = cube->nposY;
	cube->length_ray = ((double)cube->width / 2.0) / tan((60.0 / 2.0)
		* cube->rad_const);
	while (cube->map[i])
		i++;
	cube->rows = i;
}

int	main(int argc, char *argv[])
{
	t_cube	cube;
	int		i;

	ft_bzero(&cube, sizeof(t_cube));

	if (check_file(argc, argv[1]) || check_params(&cube, argv[1]) || ctrl_path(cube.img) || ctrl_player(&cube, cube.map) || ctrl_map(&cube))
		exit(EXIT_FAILURE);

	init_img(cube.img);

	// printf(MAGENTA "ctrl_map:%d\n", ctrl_map(&cube));
	// ft_printf(YELLOW "ctr_player %d\n", player);
	//=========================================================================
	// PATH TEXTURES
	i = 0;
	while (cube.img[i].path)
	{
		printf("%s\n", cube.img[i].path);
		i++;
	}

	// MEASURES IMG
	i = 0;
	while (i < 4)
	{
		printf("%d ", cube.img[0].measures[i]);
		i++;
	}
	printf("\n");

	// LST

	t_char *tmp;
	tmp = cube.img->lst;
	while (tmp != NULL)
	{
		printf(RED "\'%s\' " RESET, tmp->chars);
		printf(GREEN "%s " RESET, tmp->hex_color);
		printf(MAGENTA "r:%d g:%d b:%d\n" RESET, tmp->rgb.r, tmp->rgb.g, tmp->rgb.b);
		tmp = tmp->next;
	}

	// IMG textura

	ft_print_dptr(cube.img[0].img);

	// // MAP
	// while (cube.map[i])
	// {
	// 	printf(CYAN "%s\n" RESET, cube.map[i]);
	// 	i++;
	// }
	// i = 0;
	// RGB
	// while (i < 2)
	// {
	// 	ft_printf("r: %d\n", cube.params.colors[i].r);
	// 	ft_printf("g: %d\n", cube.params.colors[i].g);
	// 	ft_printf("b: %d\n", cube.params.colors[i].b);
	// 	i++;
	// }
	// printf(GREEN "X: %d\tY: %d\tPos X: %f\tPos Y: %f\n" RESET, cube.iX, cube.iY,
	// 	cube.nposX, cube.nposY);
	// printf(GREEN "Angle: %f\n" RESET, cube.angle);

	//=========================================================================
	// init_func(&cube);
	// ft_printf("Value: %d\n", init_mlx(&cube));
	return (0);
}

// TODO
// pasar el xmp a una estructura,
// pasasr color hexa a RGB
// hace funcion que recorra la img y devuelva el rgb segun la estructura rgb
