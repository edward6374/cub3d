/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:51:11 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/20 18:30:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

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

void	check_pos(t_cube *cube)
{
//	printf("NposX: %d\tiX: %d\tNposY: %d\tiY: %d\n", (int)(cube->nposX / 64), cube->iX, (int)(cube->nposY / 64), cube->iY);
	if ((int)(cube->nposX / 64) > cube->iX)
		cube->iX++;
	else if ((int)(cube->nposX / 64) < cube->iX)
		cube->iX--;
	if ((int)(cube->nposY / 64) > cube->iY)
		cube->iY++;
	else if ((int)(cube->nposY / 64) < cube->iY)
		cube->iY--;
	printf("iX: %d\tiY: %d\n", cube->iX, cube->iY);
}

int	keep_pressed(int keycode, t_cube *cube)
{
	double	cos_val;
	double	sin_val;

	cos_val = 2.00 * cos(cube->angle * cube->rad_const);
	sin_val = 2.00 * sin(cube->angle * cube->rad_const);
	printf("Key pressed: %d\n", keycode);
	if (keycode == 126) // Flecha arriba
	{
//		cube->posY--; //TODO: ponerlo para el minimapa
		if (cube->map[(int)fabs((cube->nposY - (10 * sin_val)) / 64.00)]\
				[(int)fabs((cube->nposX + (10 * cos_val)) / 64.00)] == '1')
			return (0);
		cube->posY -= sin_val;
		cube->posX += cos_val;
		cube->nposY -= sin_val;
		cube->nposX += cos_val;
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube, -1);
	}
	else if (keycode == 125) // Flecha abajo
	{
//		cube->posY++;
		if (cube->map[(int)(fabs(cube->nposY + (10 * sin_val)) / 64.00)]\
				[(int)fabs((cube->nposX - (10 * cos_val)) / 64.00)] == '1')
			return (0);
		cube->posY += sin_val;
		cube->posX -= cos_val;
		cube->nposY += sin_val;
		cube->nposX -= cos_val;
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube, -1);
//		create_minimap(cube, 1);
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
		create_minimap(cube, -1);
//		create_minimap(cube, 2);
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
		create_minimap(cube, -1);
//		create_minimap(cube, 3);
	}
//	read_map(cube);
	printf("X: %f\tY: %f\tPos X: %f\tPos Y: %f\n", cube->nposX, cube->nposY, cube->posX, cube->posY);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_cube *cube)
{
//	cube->mlx.status = 1;
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
//		calculate_rays(cube);
		cube->mlx.status = 0;
	}
	return (0);
}
