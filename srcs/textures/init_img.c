/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:13:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/30 11:20:36 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "libft.h"
#include "colorsft.h"

#include <fcntl.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *removeQuotes(const char *input)
{
	// Verificar si el string tiene comillas al inicio y al final
	if (input[0] == '"' && input[strlen(input) - 3] == '"')
	{
		// Calcular la longitud del nuevo string sin las comillas
		size_t len = ft_strlen(input) - 2;

		// Asignar memoria para el nuevo string sin comillas
		char *result = (char *)malloc(len + 1);

		// Copiar el contenido sin las comillas
		strncpy(result, input + 1, len);
		result[len - 2] = '\0'; // Agregar el carácter nulo al final

		return result;
	}
	else
	{
		// Si no hay comillas al inicio y al final, devolver el string original
		return strdup(input);
	}
}

char **load_img(char *path)
{
	char **file_content;

	// TODO
	printf(MAGENTA "%s\n" RESET, path);

	int fd = open(path, O_RDONLY);
	file_content = ft_file_to_dptr_m(fd);
	close(fd);

	return (file_content);
}

void init_params(char *num, int measures[])
{

	char *result = removeQuotes(num);
	char **split = ft_split(result, ' ');

	free(result);

	int i = -1;
	while (split[++i])
		measures[i] = ft_atoi(split[i]);
	ft_free_dptr(split);
}

int hex_len(char *file)
{
	int i = 0;
	int len = 0;
	int flag = 0;
	while (file[i])
	{
		if (file[i] == 'c')
			flag = 1;
		else if (file[i] == '"')
			flag = 0;
		if (flag)
			len++;
		i++;
	}
	return len - 1;
}
void init_colors(char **file, int ch, int num_colors)
{
	int i = 0;
	int len = 0;

	// Allocate a three-dimensional array

	printf(MAGENTA "num_colors %d\n" RESET, num_colors);

	while (file[i])
	{
		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
		{
			printf("%zu\n", ft_strlen(file[i]));
			printf("%d\n", hex_len(file[i]));

			printf(YELLOW "%s" RESET, file[i]);

			len = ft_strlen(file[i]) - (ch + 7);

			// Allocate memory for characters and colors
			char *charte = ft_substr(file[i], 1, ch);
			char *hex_color = ft_substr(file[i], ch + 4, len);

			printf("len: %d ", len);
			printf(RED "\'%s\' " RESET, charte);
			printf(GREEN "%s\n" RESET, hex_color);
			free(charte);
			free(hex_color);
		}
		i++;
	}
}
// void init_colors(char **file, int ch, int num_colors)
// {
// 	int i = 0;
// 	int len = 0;

// 	char **colors = malloc((num_colors + 1) * sizeof(char *));
// 	char **caracter = malloc((num_colors + 1) * sizeof(char *));

// 	while (file[i])
// 	{
// 		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
// 		{
// 			len = ft_strlen(file[i]) - (ch + 8);

// 			colors[i] = ft_substr(file[i], ch + 4, len);
// 			caracter[i] = ft_substr(file[i], 1, ch);

// 			printf("len: %d ", len);
// 			printf(RED "%s " RESET, caracter[i]);
// 			printf(GREEN "%s\n" RESET, colors[i]);
// 		}
// 		i++;
// 	}

// 	// colors[i] = NULL;
// 	for (int i = 0; colors[i]; i++)
// 	{
// 		printf(RED "%s\n" RESET, colors[i]);
// 	}

// 	// // Don't forget to free allocated memory when done
// 	// for (int j = 0; j < i; j++)
// 	// {
// 	// 	free(colors[j]);
// 	// 	free(caracter[j]);
// 	// }

// 	// Free the arrays themselves
// 	// free(colors);
// 	// free(caracter);
// }

// =========================================================================
void init_img(t_img img[])
{
	char **file_content;

	file_content = load_img(img[0].path);

	// TODO aqui while para las 4 texturas
	init_params(file_content[3], img[0].measures);
	// init_colors(file_content, params->measures[CHAR], params->measures[COLORS]);

	// //=========================================================================

	// //=========================================================================
	free(file_content);
}