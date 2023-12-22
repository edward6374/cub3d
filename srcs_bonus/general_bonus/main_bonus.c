/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:01 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 15:13:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d_bonus.h"
#include <math.h>

void	init_func(t_cube *cube)
{
	int	i;

	i = 0;
	cube->rad_const = M_PI / 180.00;
	cube->width = 1280;
	cube->height = 720;
	cube->length_ray = ((float)cube->width / 2.00) / tan((60.00 / 2.00) \
		* cube->rad_const);
	while (cube->map[i])
		i++;
	cube->rows = i;
}

int	main(int argc, char *argv[])
{
	t_cube	cube;

	ft_bzero(&cube, sizeof(t_cube));
	if (check_file(argc, argv[1]) || check_params(&cube, argv[1])
		|| ctrl_path(cube.img) || ctrl_player(&cube, cube.map)
		|| ctrl_map(&cube))
		exit(EXIT_FAILURE);
	init_img(cube.img);
	init_func(&cube);
	if (init_mlx(&cube))
		exit(EXIT_FAILURE);
	hook_mlx(&cube);
	return (0);
}
