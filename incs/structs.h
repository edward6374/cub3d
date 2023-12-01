/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/11/30 20:56:49 by nmota-bu         ###   ########.fr       */
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
	COLUM,
	ROWS,
	COLORS,
	CHAR,
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
	double small_seg;
}					t_rays;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_char
{
	char *chars;
	char *hex_color;
	t_color rgb;
	struct s_char *next;
} t_char;

typedef struct s_img
{
	char *name;
	char *path;
	int measures[4];
	t_char *lst;
	char **img;
} t_img;

typedef struct s_param
{
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
	double	posX; // posicion del jugador por el minimapa
	double	posY;
	double	nposX; // posicion del jugador en pixel
	double	nposY;
	double	angle;
	double	rad_const;
	double	length_ray;
	t_mlx	mlx;
	t_img img[4];
	t_param	params;
}			t_cube;

#endif
