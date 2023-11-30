/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:21:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/30 16:28:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d.h"
#include <stdio.h>

long hexToDecimal(char *hex)
{
	long decimal;
	int i;
	char digit;
	int value;

	decimal = 0;
	i = 0;
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

void hex_to_rgb(char *hexColor, unsigned char *red, unsigned char *green, unsigned char *blue)
{
	// Skip the '#' character
	if (*hexColor == '#')
		hexColor++;
	if (hexColor[0] == '0' && (hexColor[1] == 'x' || hexColor[1] == 'X'))
		hexColor += 2;

	// Convert hex to integer for red, green, and blue
	*red = (int)hexToDecimal(hexColor);
	hexColor += 2;
	*green = (int)hexToDecimal(hexColor);
	hexColor += 2;
	*blue = (int)hexToDecimal(hexColor);
}
