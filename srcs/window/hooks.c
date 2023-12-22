/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:51:11 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 15:27:00 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Keycode values:
 * 0   : A
 * 1   : S
 * 2   : D
 * 13  : W
 * 53  : ESC
 * 123 : Flecha izquierda
 * 124 : Flecha derecha
 */

#include "cub3d.h"
#include "structs.h"
#include <math.h>

int	exit_safe(int index, t_cube *cube)
{
	if (!index)
		ft_printf("Exit with ESC!\n");
	else
		ft_printf("Exit with the cross!\n");
	ft_free_dptr(cube->map);
	ft_free_dptr(cube->img[0].img);
	ft_free_dptr(cube->img[1].img);
	ft_free_dptr(cube->img[2].img);
	ft_free_dptr(cube->img[3].img);
	cube->map = NULL;
	cube->img[0].img = NULL;
	cube->img[1].img = NULL;
	cube->img[2].img = NULL;
	cube->img[3].img = NULL;
	exit(0);
	return (0);
}

void	arrows_pressed(int key, t_cube *cube)
{
	if (key == 123)
	{
		if (cube->angle == 358.00)
			cube->angle = 0.00;
		else if (cube->angle + 2.00 > 360.00)
			cube->angle = 360.00 - cube->angle;
		else
			cube->angle += 2.00;
	}
	else if (key == 124)
	{
		if (cube->angle == 0.00)
			cube->angle = 358.00;
		else if (cube->angle - 2.00 < 0.00)
			cube->angle = 360.00 - cube->angle;
		else
			cube->angle -= 2.00;
	}
}

int	keep_pressed(int key, t_cube *cube)
{
	int		i_xy[2];
	int		i_out[4];
	float	angle_vals[4];

	cube->dir = key;
	cube->mlx.status = 1;
	set_idx(cube, i_out, i_xy, angle_vals);
	if (key <= 13 && check_mov(cube, i_out, i_xy, cube->dir))
		return (0);
	if (key == 0)
		update_pos(cube, angle_vals, 0, COS_90);
	else if (key == 1)
		update_pos(cube, angle_vals, 1, COS);
	else if (key == 2)
		update_pos(cube, angle_vals, 1, COS_90);
	else if (key == 13)
		update_pos(cube, angle_vals, 0, COS);
	else
		arrows_pressed(key, cube);
	return (0);
}

int	esc_hook(int key, t_cube *cube)
{
	if (key == 53)
		exit_safe(0, cube);
	return (0);
}

int	loop_hook(t_cube *cube)
{
	if (cube->mlx.status == 1)
	{
		calculate_rays(cube);
//		create_minimap(cube);
		mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.win, cube->mlx.img, 0,
			0);
		cube->mlx.status = 0;
	}
	return (0);
}
