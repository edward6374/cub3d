#include <stdio.h>
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

	int i = 0;
	int num_lines = sizeof(datos) / sizeof(datos[0]);

	printf("Líneas con solo 1 o 0:\n");
	while (i < num_lines)
	{
		int j = 0;
		int contiene_1_o_0 = 1; // Suponemos que la línea contiene solo 1 o 0 hasta que se demuestre lo contrario
		while (datos[i][j] != '\0')
		{
			if (datos[i][j] != '1' && datos[i][j] != '0')
			{
				contiene_1_o_0 = 0; // La línea no contiene solo 1 o 0
				break;
			}
			j++;
		}

		if (contiene_1_o_0)
		{
			printf("%s", datos[i]);
		}

		i++;
	}
	//=========================================================================
	// int total_lines = sizeof(datos) / sizeof(datos[0]);

	// printf("Líneas con solo '1' y '0':\n");
	// int i = 0;
	// while (i < total_lines)
	// {
	// 	int has_only_01 = 1;
	// 	int j = 0;
	// 	while (datos[i][j] != '\0')
	// 	{
	// 		if (datos[i][j] != '1' && datos[i][j] != '0' && datos[i][j] != '\n' &&
	// 			datos[i][j] != ' ' && datos[i][j] != 'E')
	// 		{
	// 			has_only_01 = 0;
	// 			break;
	// 		}
	// 		j++;
	// 	}
	// 	if (has_only_01)
	// 	{
	// 		printf("%s", datos[i]);
	// 	}
	// 	i++;
	// }
}

// int i = 0;

// while (i < 23)
// {
// 	// toma(datos[i]);
// 	printf("%s", datos[i]);
// 	i++;
// }

// return 0;

