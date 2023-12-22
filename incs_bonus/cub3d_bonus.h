/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:51 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 15:16:06 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "structs_bonus.h"

/*	=======================   CALCS   =================================*/

/* ---			print			--- */
void	print_screen(t_cube *cube, float *arr);
float	calc_small(t_cube *cube, float pos, float angle, int mode);

/* ---			rays			--- */
void	calculate_rays(t_cube *cube);
int		set_segments(t_rays *r, float small_val, float long_val);

/* ---			utils			--- */
float	loop_point(t_cube *cube, t_rays *r, int mod);
void	take_direction(t_cube *cube, t_rays *r, t_angle *vals);
void	segment_values(t_cube *cube, t_rays *r, float angle, int mode);

/*	=======================   WINDOW   =================================*/

/* ---			hooks			--- */
int		esc_hook(int key, t_cube *cube);
int		exit_safe(int index, t_cube *cube);
int		loop_hook(t_cube *cube);
int		keep_pressed(int key, t_cube *cube);

/* ---			utils			--- */
int		check_mov(t_cube *cube, int *i_out, int *i_xy, int key);
void	update_pos(t_cube *cube, float *angle_vals, int sum, int idx);
void	set_idx(t_cube *cube, int *i_out, int *i_xy, float *angle_vals);

/* ---			window			--- */
int		init_mlx(t_cube *cube);
void	hook_mlx(t_cube *cube);
void	create_minimap(t_cube *cube);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

/*	=======================   MAP   =================================*/

/* ---			check_file			--- */
void	check_img(char *file);
int		check_file(int argc, char *file);
int		check_player_error(t_cube *cube, int *err, int i, int j);

/* ---			check_params			--- */
int		check_params(t_cube *cube, char *str);

/* ---			check_rgb			--- */
void	check_rgb(t_color *color, char **split);

/* ---			ctrl			--- */
int		ctrl_map(t_cube *cube);
int		ctrl_path(t_img img[]);
int		ctrl_player(t_cube *cube, char **map);

/* ---			init_map			--- */
int		init_map(t_cube *cube, char **data);

/*	=======================   TEXTURES   =================================*/

/* ---			find_char			--- */
char	*find_char(t_img *img, int x, int y);
t_color	*find_rgb(t_char *lst, char *chars, int n);

/* ---			hex_to_rgb			--- */
char	*remove_quotes(const char *input);
void	hex_to_rgb(char *hexColor, unsigned char *red, unsigned char *green,
			unsigned char *blue);

/* ---			init_colors			--- */
void	init_colors(char **file, t_img img[]);

/* ---			init_img			--- */
void	init_img(t_img *img);

#endif
