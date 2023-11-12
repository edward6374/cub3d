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

#define ROWS 15
#define COLS 15

void findA(char arr[ROWS][COLS], int row, int col)
{

	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@')
	{
		return;
	}

	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, row - 1, col); // arriba
	findA(arr, row, col + 1); // derecha
	findA(arr, row + 1, col); // abajo
	findA(arr, row, col - 1); // izquierda
}
int main()
{
	char arr[ROWS][COLS] = {
		"111111111111111",
		"100000000000001",
		"100001111100001",
		"100001   100001",
		"100001   100001",
		"100001111100001",
		"100000000111001",
		"100001111000001",
		"100001000100001",
		"100000100000001",
		"10000000S000001",
		"100000000000001",
		"  1000000000001",
		"  1000000000001",
		"111111111111111",
	};

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 'S')
			{
				findA(arr, i, j);
			}
		}
	}

	// Imprimimos el resultado
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
