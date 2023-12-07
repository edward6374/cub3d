/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:09:32 by vduchi            #+#    #+#             */
/*   Updated: 2023/12/07 18:47:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "structs.h"
#include <math.h>

void	print_pixel(t_cube *cube, int x, int y, t_color colors)
{
	my_mlx_pixel_put(&cube->mlx, x, y, ((0 & 0xff) << 24) + \
	   ((colors.r & 0xff) << 16) + ((colors.g & 0xff) << 8) + \
	   ((colors.b & 0xff)));
}

int	check_x(t_cube *cube, int idx, int *retu)
{
	int		ret;
	double	min;
	double	max;
	double	diff;
	double	piece;

	(void)retu;
	diff = fmodf(cube->walls.pos[idx], 64.00);
	min = cube->walls.pos[idx] - diff;
	max = min + 64.00;
	piece = (max - min) / 5.00;
//	ret = (((int)(cube->walls.pos[idx] - min) % (int)piece) * 64) / piece; //peor
//	ret = (int)((fmodf(cube->walls.pos[idx] - min, piece) * 64.00) / piece); //mejor
//	printf("Before\n");
	ret = (int)round(((fmodf(cube->walls.pos[idx] - min, piece) * 64.00) / piece));
	if (ret == 64)
		ret = 0;
//	printf("After\n");
//	if (dbl_btw(cube->angle, 20.00, 23.00) && idx > 550 && idx < 600)
//		printf("Ret: %d\n", ret);
//	if (*retu != idx)
//	{
//		*retu = idx;
//		printf("X: %d\t\tDiff 1: %f\tDiff 2: %d\n", idx, (fmodf(cube->walls.pos[idx] - min, piece) * 64) / piece, (int)((fmodf(cube->walls.pos[idx] - min, piece) * 64) / piece));
//		if (idx == 1279)
//			printf("\n\n\n");
//	}
	return (ret);
//	return ((int)((cube->walls.pos[idx] - min) / piece) % 2);
}

void	print_image(t_cube *cube, double height, int x, int y)
{
	int		idx;
	double	min;
	double	max;
	double	piece;
	char	*find;
	t_color	*rgb;

	static int ret;
	min = ((double)cube->height / 2.00) - height;
	max = ((double)cube->height / 2.00) + height;
	piece = (max - min) / 5.00;
//	idx = (((int)((double)y - min) % (int)piece) * 64) / piece; //peor
//	idx = (int)((fmodf((double)y - min, piece) * 64.00) / piece); //mejor
	idx = (int)round(((fmodf((double)y - min, piece) * 64.00) / piece));
	if (idx == 64)
		idx = 0;
//	if (dbl_btw(cube->angle, 20.00, 23.00) && x > 550 && x < 600)
//		printf("Y: %d\tX: %d\n", idx, check_x(cube, x));
//	find = find_char(&cube->img[0], idx, check_x(cube, x, &ret)); //para solo una imagen
	find = find_char(&cube->img[cube->walls.dir[x]], idx, check_x(cube, x, &ret));
//	if (x == 105)
//		printf("Find: %s\n", find);
	rgb = find_rgb(cube->img[cube->walls.dir[x]].lst, find, cube->img->measures[CHAR]);
//	printf("Dir: %d\tX: %d\tY: %d\tP: %p\n", cube->walls.dir[x], x, y, find);
//	printf("R: %d\tG: %d\tB: %d\n", rgb->r, rgb->g, rgb->b);
	print_pixel(cube, x, y, *rgb);
	free(find);
	
//	if (cube->walls.dir[x] == NO)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0x00CC00); //verde
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0x00CC66);
//	}
//	else if (cube->walls.dir[x] == SO)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xCC99FF); //lilla
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xE2C4FF);
//	}
//	else if (cube->walls.dir[x] == WE)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFF9933); //arancio
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFFB76E);
//	}
//	else if (cube->walls.dir[x] == EA)
//	{
//		if ((check_x(cube, x) && !((int)(((double)y - min) / piece) % 2))
//			|| (!check_x(cube, x) && (int)(((double)y - min) / piece) % 2))
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFF99CC); //rosa
//		else
//			my_mlx_pixel_put(&cube->mlx, x, y, 0xFFB9DC);
//	}
}

void	print_screen(t_cube *cube, double *arr)
{
	int		x;
	int		y;
	double	height;

	x = -1;
	while (++x < cube->width)
	{
		y = -1;
		height = ((64.00 / arr[x]) * cube->length_ray) / 2.00;
//		printf("Value: %f\tHeight; %f\n", arr[x], height);
		while (++y < cube->height)
		{
//			printf("1\n");
			if ((double)y > (double)(cube->height / 2.00) - height
				&& (double)y < (double)(cube->height / 2.00) + height)
			{
//				printf("2\n");
				print_image(cube, height, x, y);
//				printf("3\n");
			}
			else if ((double)y < (double)(cube->height / 2.00) - height)
			{
//				printf("4\n");
				print_pixel(cube, x, y, cube->params.colors[C]);
//				printf("5\n");
			}
			else
			{
//				printf("6\n");
				print_pixel(cube, x, y, cube->params.colors[F]);
//				printf("7\n");
			}
		}
//		printf("X: %d\n", x);
	}
}
