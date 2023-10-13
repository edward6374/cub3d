/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:51 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/13 19:29:00 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

enum
{
	false = 0,
	true = 1,
};

typedef struct s_color
{
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
}					t_color;

typedef struct s_param
{
	int				east;
	int				west;
	int				north;
	int				south;
	char			**textures;
	t_color			colors[2];
}					t_param;

typedef struct s_mlx
{
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				status;
	void			*mlx;
	void			*img;
	void			*win;
	char			*addr;
}					t_mlx;

typedef struct s_cube
{
	int				posX; //posicion del jugador por el minimapa
	int				posY;
	int				nposX; //posicion del jugador en pixel
	int				nposY;
	int				iX; //posicion del jugador en indice de array
	int				iY;
	int				width;
	int				height;
	int				length_ray;
	char			*east;
	char			*west;
	char			*north;
	char			*south;
	char			**map;
	double			rad_const;
	t_mlx			mlx;
	t_param			params;
}					t_cube;

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
void		calculate_rays(t_cube *cube);

#endif
