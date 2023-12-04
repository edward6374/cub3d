/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:51 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/04 17:10:13 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "structs.h"

/* ---			Hooks.c				--- */
int loop_hook(t_cube *cube);
int exit_safe(t_cube *cube, int index);
int key_hook(int keycode, t_cube *cube);
int keep_pressed(int keycode, t_cube *cube);
int mouse_hook(int button, int x, int y, t_cube *cube);
void second_key_hook(int keycode, t_cube *cube);

/* ---			Window.c			--- */
int init_mlx(t_cube *cube);
void create_minimap(t_cube *cube);
void my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

/* ---			Check_file.c			--- */
int check_params(t_cube *cube, char *str);
void map_person_point(t_cube *cube, int dir);
int check_file(int argc, char *file);
int init_map(t_cube *cube, char **data);
int ctrl_map(t_cube *cube);
int check_path_img(void);
void check_rgb(t_color *color, char **split);

/* ---			ctrl			--- */
int ctrl_path(t_img img[]);
int ctrl_player(t_cube *cube, char **map);

/* ---			Read_map.c			--- */
void read_map(t_cube *cube);

/* ---			Rays.c			--- */
int dbl_eq(double a, double b);
int dbl_btw(double angle, double min, double max);
int set_segments(t_rays *r, double small_val, double long_val);
void calculate_rays(t_cube *cube);

/* ---			Print.c			--- */
void print_screen(t_cube *cube, double *arr);
void init_colors(char **file, t_img img[]);
void init_img(t_img *img);
void hex_to_rgb(char *hexColor, unsigned char *red, unsigned char *green, unsigned char *blue);
char *find_char(t_img *img, int x, int y);
t_color *find_rgb(t_char *lst, char *chars, int n);

#endif
