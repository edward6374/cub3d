/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:13:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/29 12:15:29 by nmota-bu         ###   ########.fr       */
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

char **load_img(char **path)
{
	char **file_content;

	int fd = open(path[1], O_RDONLY);
	file_content = ft_file_to_dptr_m(fd);
	close(fd);

	return (file_content);
}

void init_params(char *num, t_param *params)
{

	char *result = removeQuotes(num);

	// printf(RED "%s" RESET, num);
	// printf(MAGENTA "%s\n" RESET, result);
	char **split = ft_split(result, ' ');

	free(result);

	int i = -1;
	while (split[++i])
	{
		// printf(ORANGE "%s\n" RESET, split[i]);
		params->measures[i] = ft_atoi(split[i]);
		// printf("s:%s d:%d\n", split[i], params[i]);
	}

	ft_free_dptr(split);
}

void init_colors(char **file, int ch)
{
	int i = 0;
	(void)ch;

	while (file[i])
	{
		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
			printf(GREEN "%s" RESET, file[i]);
		i++;
	}
}

void init_text(t_param *params)
{
	char **file_content;

	file_content = load_img(params->path);

	init_params(file_content[3], params);
	init_colors(file_content, params->measures[CHAR]);

	// TODO messusres
	for (size_t i = 0; params->measures[i]; i++)
	{
		printf(RED "d:%d\n", params->measures[i]);
	}

	//=========================================================================
	// print file
	// for (int i = 0; file_content[i] != NULL; i++)
	// {
	// 	printf("%s", file_content[i]);
	// 	// free(file_content[i]); // Liberar la memoria de cada línea
	// }
	//=========================================================================
	free(file_content);
}
