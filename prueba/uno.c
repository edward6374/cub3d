#include <stdio.h>
#include <string.h>

enum Direccion
{
	NO,
	WE,
	SO,
	EA,
};

// char *params[4] = {
// 	"./tools/assets/Wall-no.xpm",
// 	"./tools/assets/Wall-we.xpm",
// 	"./tools/assets/Wall-so.xpm",
// 	"./tools/assets/Wall-ea.xpm"};

void asignarDirecciones(char *datos[], char *params[])
{
	int i = 0;
	while (datos && datos[i])
	{
		printf("%s\n", datos[i]);
		// char *token = strtok(datos[i], " ");

		// printf("%s\n", token);
		// char *path = strtok(NULL, " ");

		// printf("token: %s path %s", token, path);
		// if (strcmp(token, "NO") == 0)
		// {
		// 	params[NO] = path;
		// }
		// else if (strcmp(token, "WE") == 0)
		// {
		// 	params[WE] = path;
		// }
		// else if (strcmp(token, "SO") == 0)
		// {
		// 	params[SO] = path;
		// }
		// else if (strcmp(token, "EA") == 0)
		// {
		// 	params[EA] = path;
		// }
		i++;
	}
}

int main()
{
	char *params[4];

	char *datos[] = {
		"NO ./tools/assets/Wall-000.xpm",
		"WE ./tools/assets/Wall-001.xpm",
		"SO ./tools/assets/Wall-004.xpm",
		"EA ./tools/assets/Wall-012.xpm"};

	asignarDirecciones(datos, params);

	// Imprimir los valores asignados a cada dirección
	// printf("NO: %s\n", params[NO]);
	// printf("WE: %s\n", params[WE]);
	// printf("SO: %s\n", params[SO]);
	// printf("EA: %s\n", params[EA]);

	return 0;
}
