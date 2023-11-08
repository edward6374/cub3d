#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

// si empieza cn '1' o ' ' hasta '\n'
// if 0 == ' ' || 0 == '1'
// sumas 1 a row para saber las lineas a copiar

int main()
{
	char *datos[] = {
		"NO ./tools/assets/Wall-000.xpm\n",
		"WE ./tools/assets/Wall-001.xpm\n",
		"SO ./tools/assets/Wall-004.xpm\n",
		"EA ./tools/assets/Wall-012.xpm\n",
		"\n",
		"C 200,200,200\n",
		"F 100,100,100\n",
		"\n",
		"\n",
		"  111111111111111111111111111111111 11111  1111111\n",
		"1111E000000000000000000000000000001 10001  1000011\n",
		"11110000000000000000000000000000001 10001  1000011\n",
		"11111000000000000000000000000000001110001  1000011\n",
		"    1000000000000000000000000000000000001  10000111111\n",
		"    1000000000110111000111111110000000001  10000000011\n",
		"    1000000001010101000100000010000000001  10000111111\n",
		"11111000000010011101000111100010000000001111000011\n",
		"10000000000100000001000000100100000000000000000011\n",
		"10000000000000000101000100000000000000000000000011\n",
		"10000000000000000101000111111110000000000000000011\n",
		"10000000000000000000000000000000000000000000000011\n",
		"11111111111111111111111111111111111111111111111111\n"};

	int total_lines = sizeof(datos) / sizeof(datos[0]);

	int i = 0;
	int row = 0;

	while (i < total_lines)
	{
		if (datos[i][0] == ' ' || datos[i][0] == '1')
			row++;
		i++;
	}
	char **map = malloc(row * sizeof(char *));

	i = 0;
	int map_index = 0;
	while (i < total_lines)
	{
		if (datos[i][0] == ' ' || datos[i][0] == '1')
		{
			map[map_index] = malloc(strlen(datos[i]) + 1);
			if (map[map_index] == NULL)
			{
				fprintf(stderr, "Error al asignar memoria\n");
				return 1;
			}

			int j = 0;
			while (datos[i][j] != '\n')
			{
				map[map_index][j] = datos[i][j];
				j++;
			}
			map[map_index][j] = '\0';
			map_index++;
		}
		i++;
	}

	map[map_index] = NULL;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}

	// otra vez lo mismo pero ahora recorriendo j para copiar los datos hasta '\n'
}

// int i = 0;

// while (i < 23)
// {
// 	// toma(datos[i]);
// 	printf("%s", datos[i]);
// 	i++;
// }

// return 0;
