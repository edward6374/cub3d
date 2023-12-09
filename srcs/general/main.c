/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:01 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/09 17:10:32 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d.h"
#include <math.h>

//	TODO
//	Nacho, tienes que hacer el init_func bien, con un archivo da leer

void init_func(t_cube *cube)
{
	int i;

	i = 0;
	cube->rad_const = M_PI / 180.00;
	cube->width = 1280;
	cube->height = 720;
	cube->length_ray = ((float)cube->width / 2.0) / tan((60.0 / 2.0) * cube->rad_const);
	while (cube->map[i])
		i++;
	cube->rows = i;
}

int main(int argc, char *argv[])
{
	t_cube cube;
	int i;

	ft_bzero(&cube, sizeof(t_cube));
	if (check_file(argc, argv[1]) || check_params(&cube, argv[1]) || ctrl_path(cube.img) || ctrl_player(&cube, cube.map) || ctrl_map(&cube))
		exit(EXIT_FAILURE);
	//	printf(MAGENTA "ctrl_map:%d\n", ctrl_map(&cube));
	// ft_printf(YELLOW "ctr_player %d\n", player);
	//=========================================================================
	
	init_img(cube.img);

	// FIND CHAR ON TEXTURE
	char *find;

	find = find_char(&cube.img[NO], 3, 33);

	printf("find char:'%s'\n", find);
	free(find);

	t_color *found = find_rgb(cube.img->lst, find, cube.img->measures[CHAR]);
	if (found != NULL)
	{
		printf(YELLOW "r:%d g:%d b:%d\n" RESET, found->r, found->g, found->b);
	}

	// PATH TEXTURES
	//	while (cube.params.path[i])
	//	{
	//		printf("%s\n", cube.params.path[i]);
	//		i++;
	//	}
	i = 0;
	// MAP
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
	i = 0;
	while (i < 4)
	{	
		t_char *tmp;
		tmp = cube.img[i].lst;
		printf("Name: %s\n", cube.img[i].path);
		while (tmp != NULL)
		{
			printf(RED "\'%s\' " RESET, tmp->chars);
			printf(GREEN "%s " RESET, tmp->hex_color);
			printf(MAGENTA "r:%d g:%d b:%d\n" RESET, tmp->rgb.r, tmp->rgb.g, tmp->rgb.b);
			tmp = tmp->next;
		}
		i++;
	}
//	printf(GREEN "X: %d\tY: %d\tPos X: %f\tPos Y: %f\n" RESET, cube.iX, cube.iY,
//		   cube.nposX, cube.nposY);
//	printf(GREEN "Angle: %f\n" RESET, cube.angle);

//	printf("First: %c\n", cube.img[0].img[3][20]);
	// IMG textura
	// ft_print_dptr(cube.img[0].img, 0);

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
	init_func(&cube);
	if (init_mlx(&cube))
		exit(EXIT_FAILURE);
	hook_mlx(&cube);
	return (0);
}

// TODO
// pasar el xmp a una estructura,
// pasasr color hexa a RGB
// hace funcion que recorra la img y devuelva el rgb segun la estructura rgb
