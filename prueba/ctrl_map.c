

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/11 20:32:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdbool.h>
#include "../libft/incs/libft.h"
#include <stdio.h>

// #define ROWS 15
// #define COLS 15

void findA(char **arr, int row, int col, int ROWS)
{
	int COLS = ft_strlen(arr[row]);

	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@')
	{
		return;
	}

	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, row - 1, ft_strlen(arr[row - 1]), ROWS); // arriba
	findA(arr, row, col + 1, ROWS);						// derecha
	findA(arr, row + 1, ft_strlen(arr[row + 1]), ROWS); // abajo
	findA(arr, row, col - 1, ROWS);						// izquierda
}
int main()
{
	char **arr = ft_file_to_dptr("map1.cub", 0);

	int i = 0;

	// // Calculamos row
	while (arr[i])
	{
		// printf("%d\n", i);
		// printf("%s\n", arr[i]);
		i++;
	}

	int ROWS = i + 1;

	i = 0;

	while (arr[i])
	{
		int j = 0;
		while (arr[i][j])
		{
			// printf("%c", arr[i][j]);
			findA(arr, i, j, ROWS);
			j++;
		}
		// printf("\n");
		i++;
	}

	// // Imprimimos el resultado
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}

	return 0;
}

// char *map[] = {
// 	"  111111111111111111111111111111111 11111  1111111",
// 	"  1E000000000000000000000000000001 10001  1000011",
// 	"  10000000000011111100000000000001 10001  1000011",
// 	" 1000000000001   1000000000000001110001  1000011",
// 	" 1110000000001   100000000000000000001  10000111111",
// 	"    100000000011 111000111111110000000001  10000000011",
// 	"    100000000101 101000111111111000000001  10000111111",
// 	"    100000001001110100011      1000000001111000011",
// 	"   1000000010000000100001      10000000000000001",
// 	"   1000000000000010100011      10000000000000001",
// 	"   1000000000000010100011111111100000000000000001",
// 	"   1000000000000000000000000000000000000000000001",
// 	"   1111111111111111111111111111111111111111111111",
// 	NULL};
