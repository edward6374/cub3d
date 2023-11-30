/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:51 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/30 11:05:52 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"

/* ---			Hooks.c				--- */
int		loop_hook(t_cube *cube);
int		exit_safe(t_cube *cube, int index);
int		key_hook(int keycode, t_cube *cube);
int		keep_pressed(int keycode, t_cube *cube);
int		mouse_hook(int button, int x, int y, t_cube *cube);
void	second_key_hook(int keycode, t_cube *cube);

/* ---			Window.c			--- */
int		init_mlx(t_cube *cube);
void	create_minimap(t_cube *cube, int dir);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

/* ---			Check_file.c			--- */
int		check_params(t_cube *cube, char *str);
// int check_map(char *argv[]);
void	map_person_point(t_cube *cube, int dir);
int		check_file(int argc, char *file);
int		init_map(t_cube *cube, char **data);
int		ctrl_map(t_cube *cube);
int		check_path_img(void);
void	check_rgb(t_color *color, char **split);

/* ---			ctrl			--- */
int ctrl_path(t_img img[]);
int		ctrl_player(t_cube *cube, char **map);

/* ---			Read_map.c			--- */
void	read_map(t_cube *cube);

/* ---			Rays.c			--- */
int		dbl_eq(double a, double b);
int		dbl_btw(double angle, double min, double max);
int		set_segments(t_rays *r, double small_val, double long_val);
void	calculate_rays(t_cube *cube);

void init_img(t_img img[]);

#endif
