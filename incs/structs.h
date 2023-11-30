/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/30 16:06:21 by vduchi           ###   ########.fr       */
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
	COS,
	SIN,
	COS_90,
	SIN_90,
};

enum
{
	NO,
	SO,
	WE,
	EA,
};

enum
{
	X,
	Y,
};

typedef struct s_values
{
	double			p_x;
	double			p_y;
	double			dist;
	double			long_seg;
	double			small_seg;
}					t_values;

typedef struct s_rays
{
	int				incr;
	int				offset;
	double			start_x;
	double			start_y;
	double			p_x;
	double			p_y;
	double			dist_x;
	double			dist_y;
	double			long_seg;
	double			small_seg;
}					t_rays;

typedef struct	s_wall
{
	int		dir[1280];
	double	pos[1280];
	double	dist[1280];
}				t_wall;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_param
{
	char *img[4]; // TODO poner array de 4 para las 4 imagenes
	char			**path;
	t_color			colors[2];
} t_param;

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
	int		iX; // posicion del jugador en indice de array
	int		iY;
	int		dir;
	int		rows;
	int		width;
	int		height;
	char	**map;
	double	nposX; // posicion del jugador en pixel
	double	nposY;
	double	angle;
	double	rad_const;
	double	length_ray;
	t_mlx	mlx;
	t_wall	walls;
	t_param	params;
}			t_cube;

#endif
