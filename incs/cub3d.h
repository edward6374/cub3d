/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:51 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/22 16:19:10 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"

/* ---			Hooks.c				--- */
int			loop_hook(t_cube *cube);
int			exit_safe(t_cube *cube, int index);
int			key_hook(int keycode, t_cube *cube);
int			keep_pressed(int keycode, t_cube *cube);
int			mouse_hook(int button, int x, int y, t_cube *cube);
void		second_key_hook(int keycode, t_cube *cube);

/* ---			Window.c			--- */
int			init_mlx(t_cube *cube);
void		create_minimap(t_cube *cube, int dir);
void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

/* ---			Check_file.c			--- */
int			check_map(t_cube *cube, char *str);
void		map_person_point(t_cube *cube, int dir);

/* ---			Read_map.c			--- */
void		read_map(t_cube *cube);

/* ---			Rays.c			--- */
int			dbl_eq(double a, double b);
int			dbl_btw(double angle, double min, double max);
int			set_segments(t_rays *r, double small_val, double long_val);
void		calculate_rays(t_cube *cube);

#endif
