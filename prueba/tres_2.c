#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		"  1111111  1111111\n",
		"1111E0001  1000011\n",
		"    10001  10000111111\n",
		"111110001111000011\n",
		"100000000000000011\n",
		"111111111111111111\n"};

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
	if (map == NULL)
	{
		fprintf(stderr, "Error al asignar memoria\n");
		return 1;
	}

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

	// Haz algo con el arreglo map aquí

	// Liberar memoria
	for (int k = 0; k < map_index; k++)
	{
		printf("%s", map[k]);
	}

	return 0;
}
