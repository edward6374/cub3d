/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:26:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/23 18:00:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define SQUARE 64
#define LEN_X 10
#define LEN_Y 5

typedef struct s_game
{
	void *mlx;
	void *win;
	void *img;
} t_game;

enum
{
	ON_KEYPRESS = 2,
	ON_DESTROY = 17,
	KEY_1 = 18, // new img & put img to windows
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_ESC = 53,
};

void key_push(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == KEY_ESC)
		exit(0);
}

void put_wall(t_game *game)
{
	int x = 0;
	int y = 0;
	while (y <= LEN_Y)
	{
		while (x < LEN_X)
		{
			mlx_put_image_to_window(game->mlx, game->win,
									game->img, x * SQUARE, y * SQUARE);
			x++;
		}
		x = 0;
		y++;
	}
}

int main(void)
{
	t_game game;
	int len;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, LEN_X * SQUARE, LEN_Y * SQUARE, "nach131");
	game.img = mlx_xpm_file_to_image(game.mlx, "../../assets/textures/green_up.xpm", &len, &len);
	// mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	put_wall(&game);
	mlx_hook(game.win, ON_DESTROY, 1L << 0, (void *)exit, &game);
	// mlx_hook(game.win, ON_KEYPRESS, 1L << 0, (void *)key_push, &game);
	mlx_key_hook(game.win, (void *)key_push, &game);
	mlx_loop(game.mlx);
	return (0);
}

// gcc -framework OpenGL -framework AppKit wall.c ../../mlx/libmlx.a && ./a.out
