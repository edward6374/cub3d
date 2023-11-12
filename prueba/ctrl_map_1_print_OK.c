#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/incs/libft.h"
#include "../libft/incs/colorsft.h"

void print_map(char **map, int row);

void findA(char **arr, int row, int col, int ROWS, int COLS)
{
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == ' ' || arr[row][col] == '1' || arr[row][col] == '@')
	{
		return;
	}

	arr[row][col] = '@';
	usleep(100000);
	print_map(arr, row);

	// Buscamos 0 en las celdas adyacentes

	findA(arr, row - 1, col, ROWS, COLS); // arriba
	findA(arr, row, col + 1, ROWS, COLS); // derecha
	findA(arr, row + 1, col, ROWS, COLS); // abajo
	findA(arr, row, col - 1, ROWS, COLS); // izquierda
}

void print_map(char **map, int row)
{
	int i = 0;

	system("clear");

	// if (row = 1)
	// 	printf("Fila 0\n");
	// else
	// 	printf("\n");
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '@')
				printf(MAGENTA "%c" RESET, map[i][j]);
			else
				printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main()
{
	char **arr = ft_file_to_dptr("map1.cub", 0);

	int i = 0;

	// Calculate ROWS
	while (arr[i])
	{
		i++;
	}

	int ROWS = i + 1;

	i = 0;
	int err = 0; // Declare err outside the loop

	while (arr[i])
	{
		int j = 0;
		while (arr[i][j])
		{
			findA(arr, i, j, ROWS, ft_strlen(arr[i]));
			j++;
		}
		i++;
	}

	printf("Err: %d", err);
	return 0;
}

// IMPRIME CHAR A CHAR

//   111111111111111111111111111111111 11111  1111111
// 1111@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@1 1@@@1  1@@@@11
// 1111@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@1 1@@@1  1@@@@11
// 11111@@@@@@@@@@@@@@@@@@@@@@@@@@@@@111@@@1  1@@@@11
//     1@@@@@@@@@@@@111111@@11111@@@@@@@@@1  1@@@@111111
//     1@@@@@@@@@@@@1            1@@@@@@@@@1  1@@@@@@@@11
//     1@@@@@@@@@@@@1            1@@@@@@@@@1  1@@@@111111
// 11111@@@@@@@@@@@@1            1@@@@@@@@@1111@@@@11
// 1@@@@@@@@@@1@@@@@1            1@@@@@@@@@@@@@@@@@11
// 1@@@@@@@@@@@@@@@@1            1@@@@@@@@@@@@@@@@@11
// 1@@@@@@@@@@@@@@@@11111111111111@@@@@@@@@@@@@@@@@11
// 1@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@11
// 11111111111111111111111111111111111111111111111111
