/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:06 by vduchi            #+#    #+#             */
/*   Updated: 2023/10/24 17:49:42 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../libft/incs/libft.h"
# include "../mlx/mlx.h"

enum
{
	false = 0,
	true = 1,
};

typedef struct s_rays
{
	int		incr;
	int		offset;
	double	p_x;
	double	p_y;
	double	dist_x;
	double	dist_y;
	double	start_x;
	double	start_y;
	double	long_seg;
	double	small_seg;
}			t_rays;

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
	double			angle;
	double			rad_const;
	t_mlx			mlx;
	t_param			params;
}					t_cube;

#endif
