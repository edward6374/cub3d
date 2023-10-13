/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:01 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/13 15:26:24 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

//	TODO
//	Nacho, tienes que hacer el init_func bien, con un archivo da leer

void	init_func(t_cube *cube)
{
	cube->rad_const = M_PI / 180.0;
	cube->width = 1200;
	cube->height = 800;
//	cube->height = 1200;
	cube->east = NULL;
	cube->west = NULL;
	cube->north = NULL;
	cube->south = NULL;
	cube->params.east = 3;
	cube->params.west = 4;
	cube->params.north = 5;
	cube->params.south = 6;
	cube->params.textures = ft_calloc(sizeof(char *), 5);
	cube->params.textures[0] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/east");
	cube->params.textures[1] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/west");
	cube->params.textures[2] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/north");
	cube->params.textures[3] = ft_strdup("/Users/vduchi/Desktop/cub3d/textures/south");
	cube->params.textures[4] = NULL;
	cube->params.colors[0].R = 124; // suelo
	cube->params.colors[0].G = 124;
	cube->params.colors[0].B = 124;
	cube->params.colors[1].R = 196; // techo
	cube->params.colors[1].G = 196;
	cube->params.colors[1].B = 196;
	cube->map = ft_calloc(sizeof(char *), 16);
	cube->map[0] = ft_strdup("1111111111111111");
	cube->map[1] = ft_strdup("1000000000000001");
	cube->map[2] = ft_strdup("1000011110000001");
	cube->map[3] = ft_strdup("1000011111110001");
	cube->map[4] = ft_strdup("1000011110000001");
	cube->map[5] = ft_strdup("1000000000000001");
	cube->map[6] = ft_strdup("100000N001110001");
	cube->map[7] = ft_strdup("1000000000000001");
	cube->map[8] = ft_strdup("1000000000000001");
	cube->map[9] = ft_strdup("1000000000000001");
	cube->map[10] = ft_strdup("1000000000000001");
	cube->map[11] = ft_strdup("1000000000000001");
	cube->map[12] = ft_strdup("1000000000000001");
	cube->map[13] = ft_strdup("1000000000000001");
	cube->map[14] = ft_strdup("1111111111111111");
	cube->map[15] = NULL;
	int	i = -1;
	int	j = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
			if (cube->map[i][j] == 'N')
				break ;
		if (cube->map[i][j] == 'N')
			break ;
	}
//	printf("Pos x: %d\tPos y: %d\n", j, i);
	cube->nposX = j;
	cube->nposY = i;
}

int	main(int argc, char *argv[])
{
	int		err;
	t_cube	cube;

	(void)argv;
	if (argc == 1)
		return (ft_printf("Map file name required!\n"));
	else if (argc > 3)
		return (ft_printf("Too many arguments\n"));
	init_func(&cube);
	err = check_map(&cube, argv[1]);
	if (err == 1)
		return (ft_printf("Map error\n"));
	else if (err > 1)
		return (ft_printf("Malloc error\n"));
	ft_printf("Value: %d\n", init_mlx(&cube));
	return (0);
}
