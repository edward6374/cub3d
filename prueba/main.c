/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:01 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/24 15:38:44 by nmota-bu         ###   ########.fr       */
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
	// cube->east = NULL;
	// cube->west = NULL;
	// cube->north = NULL;
	// cube->south = NULL;
	// cube->params.east = 3;
	// cube->params.west = 4;
	// cube->params.north = 5;
	// cube->params.south = 6;
	// cube->params.textures = ft_calloc(sizeof(char *), 5);
	// cube->params.textures[NO] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/east");
	// cube->params.textures[SO] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/west");
	// cube->params.textures[WE] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/north");
	// cube->params.textures[EA] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/south");
	// cube->params.textures[4] = NULL;
	// cube->params.colors[F].r = 124; // suelo
	// cube->params.colors[F].g = 124;
	// cube->params.colors[F].b = 124;
	// cube->params.colors[C].r = 196; // techo
	// cube->params.colors[C].g = 196;
	// cube->params.colors[C].b = 196;
	// cube->map = ft_calloc(sizeof(char *), 16);
	// cube->map[0] = ft_strdup("111111111111111");
	// cube->map[1] = ft_strdup("100000000000001");
	// cube->map[2] = ft_strdup("100001111000001");
	// cube->map[3] = ft_strdup("100001111111001");
	// cube->map[4] = ft_strdup("100001111110001");
	// cube->map[5] = ft_strdup("1000000N0000001");
	// cube->map[6] = ft_strdup("100000000111001");
	// cube->map[7] = ft_strdup("100000000000001");
	// cube->map[8] = ft_strdup("100000000000001");
	// cube->map[9] = ft_strdup("100000000000001");
	// cube->map[10] = ft_strdup("100000000000001");
	// cube->map[11] = ft_strdup("100000000000001");
	// cube->map[12] = ft_strdup("100000000000001");
	// cube->map[13] = ft_strdup("100000000000001");
	// cube->map[14] = ft_strdup("111111111111111");
	// cube->map[15] = NULL;
	//==============ctrl_player=================================================
	// int	i = -1;
	// int	j = -1;
	// while (cube->map[++i])
	// {
	// 	j = -1;
	// 	while (cube->map[i][++j])
	// 		if (cube->map[i][j] == 'N')
	// 			break ;
	// 	if (cube->map[i][j] == 'N')
	// 		break ;
	// }
	// cube->iX = j;
	// cube->iY = i;
	// cube->posX = 0;
	// cube->posY = 0;
	// cube->nposX = (double)((j * 64) + 32);
	// cube->nposY = (double)((i * 64) + 32);
	// printf("X: %d\tY: %d\tPos X: %f\tPos Y: %f\n", j, i,
	//	cube->nposX,cube->nposY);
	//=========================================================================
	// cube->angle = 180.00;
	cube->posX = cube->nposX;
	cube->posY = cube->nposY;
	cube->length_ray = ((double)cube->width / 2.0) / tan((60.0 / 2.0)
		* cube->rad_const);
	while (cube->map[i])
		i++;
	cube->rows = i;
}
//=========================================================================
#define SQUARE 64
#define LEN_X 10
#define LEN_Y 5

enum
{
	ON_KEYPRESS = 2,
	ON_DESTROY = 17,
	KEY_1 = 18, // new img & put img to windows
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_ESC = 53,
};
void key_push(int key)
{
	printf("%d\n", key);
	if (key == KEY_ESC)
		exit(0);
}

void init_img_dos(void *mlx, char **path, char *img[])
{
	int i = 0;
	int len;

	while (path[i])
	{
		// printf("\t%s\n", path[i]);
		img[i] = mlx_xpm_file_to_image(mlx, path[i], &len, &len);
		// printf("%s\n", img[i]);
		i++;
	}
}

void tokemo(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	cube->mlx.win = mlx_new_window(cube->mlx.mlx, LEN_X * SQUARE, LEN_Y * SQUARE, "nach131");
	init_img_dos(cube->mlx.mlx, cube->params.path, cube->params.img);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win,
							cube->params.img[0], 1 * SQUARE, 1 * SQUARE);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win,
							cube->params.img[1], 2 * SQUARE, 1 * SQUARE);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win,
							cube->params.img[2], 3 * SQUARE, 1 * SQUARE);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win,
							cube->params.img[3], 4 * SQUARE, 1 * SQUARE);
	mlx_key_hook(cube->mlx.win, (void *)key_push, NULL);
	mlx_loop(cube->mlx.mlx);
}
//=========================================================================
int	main(int argc, char *argv[])
{
	t_cube	cube;
	int		i;

	ft_bzero(&cube, sizeof(t_cube));
	if (check_file(argc, argv[1]) || check_params(&cube, argv[1])
		|| ctrl_path(cube.params.path) || ctrl_player(&cube, cube.map)
		|| ctrl_map(&cube))
		exit(EXIT_FAILURE);
	// printf(MAGENTA "ctrl_map:%d\n", ctrl_map(&cube));
	// ft_printf(YELLOW "ctr_player %d\n", player);
	//=========================================================================
	i = 0;
	// PATH TEXTURES
	while (cube.params.path[i])
	{
		printf("%s\n", cube.params.path[i]);
		i++;
	}
	i = 0;
	// MAP
	while (cube.map[i])
	{
		printf(CYAN "%s\n" RESET, cube.map[i]);
		i++;
	}
	i = 0;
	// RGB
	while (i < 2)
	{
		ft_printf("r: %d\n", cube.params.colors[i].r);
		ft_printf("g: %d\n", cube.params.colors[i].g);
		ft_printf("b: %d\n", cube.params.colors[i].b);
		i++;
	}
	printf(GREEN "X: %d\tY: %d\tPos X: %f\tPos Y: %f\n" RESET, cube.iX, cube.iY,
		cube.nposX, cube.nposY);
	printf(GREEN "Angle: %f\n" RESET, cube.angle);
	//=========================================================================
	tokemo(&cube);
	//=========================================================================
	// init_func(&cube);
	// ft_printf("Value: %d\n", init_mlx(&cube));
	return (0);
}

// TODO
// map falta controlar que el mapa este rodeado de 1 interior 0
