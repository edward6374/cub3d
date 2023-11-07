/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/07 18:05:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../libft/incs/libft.h"
# include "../mlx/mlx.h"

// const static char *g_file[] = {
// 	"Error\nMap file name required.",
// 	"Error\nToo many arguments.",
// 	"Error\nFile map does not have the extension .map."};

enum
{
	false = 0,
	true = 1,
};

enum
{
	F, // FLOOR,
	C, // CEILING,
};

enum
{
	NO,
	SO,
	WE,
	EA,
};

typedef struct s_values
{
	double	p_x;
	double	p_y;
	double	dist;
	double	long_seg;
	double	small_seg;
}			t_values;

typedef struct s_rays
{
	int			incr;
	int			offset;
	double		start_x;
	double		start_y;
	double	p_x;
	double	p_y;
	double	dist_x;
	double	dist_y;
	double	long_seg;
	double	small_seg;
//	t_values	x;
//	t_values	y;
}				t_rays;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
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
	double			nposX; //posicion del jugador en pixel
	double			nposY;
	double			angle;
	double			rad_const;
	t_mlx			mlx;
	t_param			params;
}					t_cube;

#endif