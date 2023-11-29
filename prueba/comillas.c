/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comillas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:56:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/29 11:33:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *removeQuotes(const char *input)
{
	// Verificar si el string tiene comillas al inicio y al final
	if (input[0] == '"' && input[strlen(input) - 2] == '"')
	{
		// Calcular la longitud del nuevo string sin las comillas
		size_t len = strlen(input) - 2;

		// Asignar memoria para el nuevo string sin comillas
		char *result = (char *)malloc(len + 1);

		// Copiar el contenido sin las comillas
		strncpy(result, input + 1, len);
		result[len] = '\0'; // Agregar el carácter nulo al final

		return result;
	}
	else
	{
		// Si no hay comillas al inicio y al final, devolver el string original
		return strdup(input);
	}
}

int main(void)
{
	// char *str = "\"64 64 4 1 ,\"";
	char *str = strdup("\"64 64 4 1 \",");
	char *result = removeQuotes(str);

	printf("%s\n", str);
	printf("%s\n", result);
	free(result);
}
