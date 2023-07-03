/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:01 by vduchi            #+#    #+#             */
/*   Updated: 2023/07/03 18:48:17 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_func(t_cube *cube)
{
	cube->east = NULL;
	cube->west = NULL;
	cube->north = NULL;
	cube->south = NULL;
}

int	check_map(t_cube *cube, char *str)
{
	int	map;

	(void)cube;
	map = open(str, O_RDONLY);
	if (map == -1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		err;
	t_cube	cube;

	if (argc == 1)	
		return (ft_printf("Map file name required!\n"));
	if (argc > 3)
		return (ft_printf("Too many arguments\n"));
	init_func(&cube);
	err = check_map(&cube, argv[1]) == 1;
	if (err == 1)
		return (ft_printf("Map error\n"));
	else if (err > 1)
		return (ft_printf("Malloc error\n"));
	return (0);
}
