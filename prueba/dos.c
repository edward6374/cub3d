#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strpbrk(const char *str, const char *charset)
{
	const char *char_ptr;

	while (*str != '\0')
	{
		char_ptr = charset;
		while (*char_ptr != '\0')
		{
			if (*char_ptr == *str)
				return ((char *)str);
			char_ptr++;
		}
		str++;
	}
	return (NULL);
}

char *ft_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start;
	char *token_end;

	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);

	// Encontrar el inicio del token
	token_start = next_token;

	// Encontrar el final del token
	token_end = ft_strpbrk(token_start, delim);

	// Si se encontró el delimitador, reemplazarlo con '\0'
	if (token_end != NULL)
	{
		*token_end = '\0';
		next_token = token_end + 1;
	}
	else
		next_token = NULL;

	return (token_start);
}

void toma(char *str)
{
	char *token;

	// Crear una copia de la cadena original para no modificarla
	char *str_copy = strdup(str);

	token = ft_strtok(str_copy, " ");

	while (token != NULL)
	{
		// Imprimir el token actual
		printf("%s\n", token);

		// Obtener el siguiente token
		token = ft_strtok(NULL, " ");
	}

	// Liberar la memoria de la copia de la cadena
	free(str_copy);
}

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
		"11111111111111111111111111111111111 11111  1111111\n",
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

	while (i < 21)
	{
		// toma(datos[i]);
		printf("%s",datos[i]);
		i++;
	}

	return 0;
}
