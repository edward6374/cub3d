/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:51:11 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/30 14:34:52 by vduchi           ###   ########.fr       */
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
	ft_printf("Second key hook: %d\n", keycode);
}

int	key_hook(int keycode, t_cube *cube)
{
	if (keycode == 53)
		exit_safe(cube, 0);
	else
		second_key_hook(keycode, cube);
	return (0);
}

int	loop_hook(t_cube *cube)
{
	if (cube->mlx.status == 1)
	{
		ft_printf("Loop hook\n");
		cube->mlx.status = 0;
	}
	return (0);
}
