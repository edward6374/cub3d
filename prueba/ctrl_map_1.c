#include <stdio.h>
#include <stdbool.h>
#include "../libft/incs/libft.h"

void findA(char **arr, int row, int col, int ROWS, int COLS)
{
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == ' ' || arr[row][col] == '1' || arr[row][col] == '@')
	{
		return;
	}

	arr[row][col] = '@';

	// Buscamos 0 en las celdas adyacentes
	findA(arr, row - 1, col, ROWS, COLS); // arriba
	findA(arr, row, col + 1, ROWS, COLS); // derecha
	findA(arr, row + 1, col, ROWS, COLS); // abajo
	findA(arr, row, col - 1, ROWS, COLS); // izquierda
}

int main()
{
	char **arr = ft_file_to_dptr("map1.cub", 0);

	int i = 0;

	// Calculamos row
	while (arr[i])
	{
		i++;
	}

	int ROWS = i + 1;

	i = 0;

	while (arr[i])
	{
		int j = 0;
		while (arr[i][j])
		{
			// if (arr[i][i] == 'E')

			findA(arr, i, j, ROWS, ft_strlen(arr[i]));
			j++;
		}
		i++;
	}

	// Imprimimos el resultado
	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}

	return 0;
}

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
