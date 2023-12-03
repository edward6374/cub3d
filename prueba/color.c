#include <stdio.h>
#include <stdlib.h>

long hexToDecimal(char *hex)
{
	long decimal = 0;
	int i = 0;

	// Ignore the "0x" prefix if present
	// if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
	// 	hex += 2;
	// i = 2;

	// Process each hexadecimal digit
	// while (hex[i] != '\0')
	while (i < 2)
	{
		char digit = hex[i];
		int value;

		if (digit >= '0' && digit <= '9')
			value = digit - '0';
		else if (digit >= 'A' && digit <= 'F')
			value = 10 + (digit - 'A');
		else if (digit >= 'a' && digit <= 'f')
			value = 10 + (digit - 'a');
		// else
		// {
		// 	// Invalid character in hexadecimal number
		// 	printf("Error: Invalid character in hexadecimal number: %c\n", digit);
		// 	return 0;
		// }

		decimal = decimal * 16 + value;
		i++;
	}

	return decimal;
}

void hexToRGB(char *hexColor, int *red, int *green, int *blue)
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

int main()
{
	// char *hexColor = "#329664";
	char *hexColor = "0x8b008b";
	int red, green, blue;

	// Convert hex to RGB
	hexToRGB(hexColor, &red, &green, &blue);

	// Print the results
	printf("Red: %d\n", red);
	printf("Green: %d\n", green);
	printf("Blue: %d\n", blue);

	return 0;
}
