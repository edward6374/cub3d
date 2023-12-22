/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/22 15:15:50 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "mlx.h"
# include "libft.h"

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

enum
{
	COLUM,
	ROWS,
	COLORS,
	CHAR,
};

typedef struct s_values
{
	float	p_x;
	float	p_y;
	float	dist;
	float	long_seg;
	float	small_seg;
}			t_values;

typedef struct s_rays
{
	int		incr;
	int		offset;
	float	start_x;
	float	start_y;
	float	p_x;
	float	p_y;
	float	dist_x;
	float	dist_y;
	float	long_seg;
	float	small_seg;
}			t_rays;

typedef struct s_wall
{
	int		dir[1280];
	float	pos[1280];
	float	dist[1280];
}			t_wall;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_char
{
	t_color			rgb;
	char			*chars;
	char			*hex_color;
	struct s_char	*next;
}					t_char;

typedef struct s_img
{
	int		measures[4];
	char	*name;
	char	*path;
	char	**img;
	t_char	*lst;
}			t_img;

typedef struct s_param
{
	t_color	colors[2];
}			t_param;

typedef struct s_mlx
{
	int		endian;
	int		status;
	int		line_length;
	int		bits_per_pixel;
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
}			t_mlx;

typedef struct s_point
{
	int		x;
	int		y;
	int		len;
	float	new_val;
}			t_point;

typedef struct s_angle
{
	int		idx;
	float	diff;
	float	angle;
	float	cos_angle;
}			t_angle;

typedef struct s_cube
{
	int		i_x;
	int		i_y;
	int		dir;
	int		rows;
	int		width;
	int		height;
	char	**map;
	float	npos_x;
	float	npos_y;
	float	angle;
	float	rad_const;
	float	length_ray;
	t_mlx	mlx;
	t_img	img[4];
	t_wall	walls;
	t_param	params;
}			t_cube;

#endif
