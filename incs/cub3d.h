/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:51 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/27 19:58:28 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"

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
	char			*east;
	char			*west;
	char			*north;
	char			*south;
	char			**map;
	t_mlx			mlx;
	t_param			params;
}					t_cube;

/* ---			Hooks.c				--- */
int					loop_hook(t_cube *cube);
int					exit_safe(t_cube *cube, int index);
int					key_hook(int keycode, t_cube *cube);
int					mouse_hook(int button, int x, int y, t_cube *cube);
void				second_key_hook(int keycode, t_cube *cube);

/* ---			Window.c			--- */
int init_mlx(t_cube *cube);

#endif
