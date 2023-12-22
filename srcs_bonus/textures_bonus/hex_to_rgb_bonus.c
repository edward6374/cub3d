/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgb_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:21:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/22 15:17:41 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d_bonus.h"
#include <stdio.h>

char	*remove_quotes(const char *input)
{
	size_t	len;
	char	*result;

	if (input[0] == '"' && input[strlen(input) - 3] == '"')
	{
		len = ft_strlen(input) - 2;
		result = (char *)malloc(len + 1);
		strncpy(result, input + 1, len);
		result[len - 2] = '\0';
		return (result);
	}
	return (strdup(input));
}

long	hex_to_decimal(char *hex)
{
	int		i;
	int		value;
	char	digit;
	long	decimal;

	i = 0;
	decimal = 0;
	while (i < 2)
	{
		digit = hex[i];
		if (digit >= '0' && digit <= '9')
			value = digit - '0';
		else if (digit >= 'A' && digit <= 'F')
			value = 10 + (digit - 'A');
		else if (digit >= 'a' && digit <= 'f')
			value = 10 + (digit - 'a');
		decimal = decimal * 16 + value;
		i++;
	}
	return (decimal);
}

void	hex_to_rgb(char *hexColor, unsigned char *red, unsigned char *green,
	unsigned char *blue)
{
	if (*hexColor == '#')
		hexColor++;
	if (hexColor[0] == '0' && (hexColor[1] == 'x' || hexColor[1] == 'X'))
		hexColor += 2;
	*red = (int)hex_to_decimal(hexColor);
	hexColor += 2;
	*green = (int)hex_to_decimal(hexColor);
	hexColor += 2;
	*blue = (int)hex_to_decimal(hexColor);
}
