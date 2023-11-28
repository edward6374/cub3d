/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:51:11 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/28 16:56:34 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs.h"
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
	if ((int)(cube->nposX / 64) > cube->iX)
		cube->iX++;
	else if ((int)(cube->nposX / 64) < cube->iX)
		cube->iX--;
	if ((int)(cube->nposY / 64) > cube->iY)
		cube->iY++;
	else if ((int)(cube->nposY / 64) < cube->iY)
		cube->iY--;
}

int	check_movement(t_cube *cube, int *idx_diff, int *idx_xy)
{
	if ((dbl_eq(cube->angle, 0.00) || dbl_btw(cube->angle, 0.00, 90.00)) && (cube->map[idx_diff[NO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[EA]] == '1'))
		return (1);
	else if ((dbl_eq(cube->angle, 90.00) || dbl_btw(cube->angle, 90.00, 180.00)) && (cube->map[idx_diff[NO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[WE]] == '1'))
		return (1);
	else if ((dbl_eq(cube->angle, 180.00) || dbl_btw(cube->angle, 180.00, 270.00)) && (cube->map[idx_diff[SO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[WE]] == '1'))
		return (1);
	else if ((dbl_eq(cube->angle, 270.00) || dbl_btw(cube->angle, 270.00, 360.00)) && (cube->map[idx_diff[SO]][idx_xy[0]] == '1' || cube->map[idx_xy[1]][idx_diff[EA]] == '1'))
		return (1);
	return (0);
}

void set_idx(t_cube *cube, int *idx_diff, int *idx_xy, double *angle_vals)
{
	double	incr;

	incr = 10.00;
	if (cube->dir == 2)
		incr *= -1.00;
	idx_xy[0] = (int)fabs(cube->nposX / 64.00);
	idx_xy[1] = (int)fabs(cube->nposY / 64.00);
	idx_diff[NO] = (int)fabs((cube->nposY - incr) / 64.00);
	idx_diff[SO] = (int)fabs((cube->nposY + incr) / 64.00);
	idx_diff[WE] = (int)fabs((cube->nposX - incr) / 64.00);
	idx_diff[EA] = (int)fabs((cube->nposX + incr) / 64.00);
	angle_vals[COS] = 2.00 * cos(cube->angle * cube->rad_const);
	angle_vals[SIN] = 2.00 * sin(cube->angle * cube->rad_const);
	angle_vals[COS_90] = 2.00 * cos((cube->angle + 90.00) * cube->rad_const);
	angle_vals[SIN_90] = 2.00 * sin((cube->angle + 90.00) * cube->rad_const);
}

int	keep_pressed(int keycode, t_cube *cube)
{
	int		idx_xy[2];
	int		idx_diff[4];
	double	angle_vals[4];

	if (keycode == 0) // A
	{
		cube->dir = 1;
		set_idx(cube, idx_diff, idx_xy, angle_vals);
		if (check_movement(cube, idx_diff, idx_xy))
			return (0);
		cube->nposY -= angle_vals[SIN_90];
		cube->nposX += angle_vals[COS_90];
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube);
	}
	else if (keycode == 1) // S
	{
		cube->dir = 2;
		set_idx(cube, idx_diff, idx_xy, angle_vals);
		if (check_movement(cube, idx_diff, idx_xy))
			return (0);
		cube->nposY += angle_vals[SIN];
		cube->nposX -= angle_vals[COS];
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube);
	}
	else if (keycode == 2) // D
	{
		cube->dir = 3;
		set_idx(cube, idx_diff, idx_xy, angle_vals);
		if (check_movement(cube, idx_diff, idx_xy))
			return (0);
		cube->nposY += angle_vals[SIN_90];
		cube->nposX -= angle_vals[COS_90];
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube);
	}
	else if (keycode == 13) // W
	{
		cube->dir = 4;
		set_idx(cube, idx_diff, idx_xy, angle_vals);
		if (check_movement(cube, idx_diff, idx_xy))
			return (0);
		cube->nposY -= angle_vals[SIN];
		cube->nposX += angle_vals[COS];
		check_pos(cube);
		calculate_rays(cube);
		create_minimap(cube);
	}
	else if (keycode == 123) // Flecha izquierda
	{
		if (dbl_eq(cube->angle, 358.00))
			cube->angle = 0.00;
		else if (cube->angle + 2.00 > 360.00)
			cube->angle = 360.00 - cube->angle;
		else
			cube->angle += 2.00;
		calculate_rays(cube);
		create_minimap(cube);
	}
	else if (keycode == 124) // Flecha derecha
	{
		if (dbl_eq(cube->angle, 0.00))
			cube->angle = 358.00;
		else if (cube->angle - 2.00 < 0.00)
			cube->angle = 360.00 - cube->angle;
		else
			cube->angle -= 2.00;
		calculate_rays(cube);
		create_minimap(cube);
	}
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
