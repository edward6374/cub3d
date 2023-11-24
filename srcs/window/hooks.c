/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:51:11 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/24 13:31:26 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

#ifndef NO
# define NO 0
#endif
#ifndef SO
# define SO 1
#endif
#ifndef WE
# define WE 2
#endif
#ifndef EA
# define EA 3
#endif

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
	//	printf("NposX: %d\tiX: %d\tNposY: %d\tiY: %d\n", (int)(cube->nposX
	//			/ 64), cube->iX, (int)(cube->nposY / 64), cube->iY);
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

int	check_movement(t_cube *cube, int *idx_diff, int *idx_xy)
{
	if ((dbl_eq(cube->angle, 0.00) || dbl_btw(cube->angle, 0.00, 90.00)) && (cube->map[idx_diff[NO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[EA]] == '1'))
		return (1);
	else if ((dbl_eq(cube->angle, 90.00) || dbl_btw(cube->angle, 90.00, 180.00)) && (cube->map[idx_diff[NO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[WE]] == '1'))
		return (1);
	else if ((dbl_eq(cube->angle, 180.00) || dbl_btw(cube->angle, 180.00,
													 270.00)) &&
			 (cube->map[idx_diff[SO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[WE]] == '1'))
		return (1);
	else if ((dbl_eq(cube->angle, 270.00) || dbl_btw(cube->angle, 270.00,
													 360.00)) &&
			 (cube->map[idx_diff[SO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[EA]] == '1'))
		return (1);
	return (0);
}

void set_idx(t_cube *cube, int *idx_diff, int *idx_xy, double *angle_vals)
{
	idx_xy[0] = (int)fabs(cube->nposX / 64.00);
	idx_xy[1] = (int)fabs(cube->nposY / 64.00);
	idx_diff[NO] = (int)fabs((cube->nposY - 10.00) / 64.00);
	idx_diff[SO] = (int)fabs((cube->nposY + 10.00) / 64.00);
	idx_diff[WE] = (int)fabs((cube->nposX + 10.00) / 64.00);
	idx_diff[EA] = (int)fabs((cube->nposX - 10.00) / 64.00);
	angle_vals[COS] = 2.00 * cos(cube->angle * cube->rad_const);
	angle_vals[SIN] = 2.00 * sin(cube->angle * cube->rad_const);
}

int	keep_pressed(int keycode, t_cube *cube)
{
	int		idx_xy[2];
	int		idx_diff[4];
	double angle_vals[2];

	set_idx(cube, idx_diff, idx_xy, angle_vals);
	printf("Key: %d\tCos: %f\tSin: %f\n", keycode, angle_vals[COS],
		   angle_vals[SIN]);
	if (keycode == 126) // Flecha arriba
	{
		//		cube->posY--; //TODO: ponerlo para el minimapa
		if (check_movement(cube, idx_diff, idx_xy))
			return (0);
		cube->posY -= angle_vals[SIN];
		cube->posX += angle_vals[COS];
		cube->nposY -= angle_vals[SIN];
		cube->nposX += angle_vals[COS];
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube, -1);
	}
	else if (keycode == 125) // Flecha abajo
	{
		//		cube->posY++;
		if (check_movement(cube, idx_diff, idx_xy))
			return (0);
		cube->posY += angle_vals[SIN];
		cube->posX -= angle_vals[COS];
		cube->nposY += angle_vals[SIN];
		cube->nposX -= angle_vals[COS];
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
	printf("X: %f\tY: %f\tPos X: %f\tPos Y: %f\n", cube->nposX, cube->nposY,
		   cube->posX, cube->posY);
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
