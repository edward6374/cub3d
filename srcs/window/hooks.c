/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:51:11 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/24 17:11:15 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_safe(t_cube *cube, int index)
{
	(void)cube;
	if (!index)
		ft_printf("Exit with ESC!\n");
	else
		ft_printf("Exit with the cross!\n");
	exit(0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cube *cube)
{
	(void)x;
	(void)y;
	(void)cube;
	(void)button;
	ft_printf("Mouse hook\n");
	cube->mlx.status = 1;
	return (0);
}

void	second_key_hook(int keycode, t_cube *cube)
{
	(void)cube;
	(void)keycode;
}

int	keep_pressed(int keycode, t_cube *cube)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 126) // Flecha arriba
	{
		cube->posY--;
		cube->nposY--;
		calculate_rays(cube);
		create_minimap(cube, 0);
	}
	else if (keycode == 125) // Flecha abajo
	{
		cube->posY++;
		cube->nposY++;
		calculate_rays(cube);
		create_minimap(cube, 1);
	}
	else if (keycode == 124) // Flecha derecha
	{
//		cube->posX++;
//		cube->nposX++;
		if (cube->angle - 2.00 < 0.00)
			cube->angle = 360.00 - cube->angle;
		else
			cube->angle -= 2.00;
		calculate_rays(cube);
		create_minimap(cube, 2);
	}
	else if (keycode == 123) // Flecha izquierda
	{
//		cube->posX--;
//		cube->nposX--;
		if (cube->angle + 2.00 > 360.00)
			cube->angle = 360.00 - cube->angle;
		else
			cube->angle += 2.00;
		calculate_rays(cube);
		create_minimap(cube, 3);
	}
	printf("X: %d\tY: %d\n", cube->nposX, cube->nposY);
	return (0);
}

int	key_hook(int keycode, t_cube *cube)
{
	cube->mlx.status = 1;
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit_safe(cube, 0);
	// else if (keycode == 126) // Flecha arriba
	// {
	// 	cube->posY--;
	// 	map_person_point(cube);
	// }
	// else if (keycode == 125) // Flecha abajo
	// {
	// 	cube->posY++;
	// 	map_person_point(cube);
	// }
	// else if (keycode == 124) // Flecha derecha
	// {
	// 	cube->posX++;
	// 	map_person_point(cube);
	// }
	// else if (keycode == 123) // Flecha izquierda
	// {
	// 	cube->posX--;
	// 	map_person_point(cube);
	// }
	// second_key_hook(keycode, cube);
	return (0);
}

int	loop_hook(t_cube *cube)
{
	if (cube->mlx.status == 1)
	{
//		ft_printf("Loop hook\n");
		calculate_rays(cube);
		cube->mlx.status = 0;
	}
	return (0);
}
