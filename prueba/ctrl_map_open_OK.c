#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/incs/libft.h"
#include "../libft/incs/colorsft.h"

// cheaquea si esta abierto

void print_map(char **map)
{
	int i = 0;

	i = 0;

	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			// if (map[i][j] == '@')
			printf(MAGENTA "%c" RESET, map[i][j]);
			// else
			// printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int check_map_format(char **map, int height)
{

	int i = -1;
	while (map[++i]) // Iterate through each row of the map
	{
		int j = -1;
		while (map[i][++j]) // Iterate through each character of the current row
		{
			if (ft_strchr("0NSWE", map[i][j])) // Check if the character is one of '0', 'N', 'S', 'W', or 'E'
			{
				if (i == 0 || i == height - 1 || j == 0 || j == ft_strlen(map[i]) - 1)
					return (1); // Return -1 if the character is at the border of the map

				// Check if the character is adjacent to a space (' ')
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
					map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
				{
					return (1); // Return 1 if the character is adjacent to a space
				}
			}
		}
	}
	return (0); // Return 0 if the map format is valid
}

int main()
{
	char **map = ft_file_to_dptr("map1.cub", 0);

	int i = 0;

	// Calculate ROWS
	while (map[i])
	{
		i++;
	}

	int ROWS = i + 1;

	int err = check_map_format(map, ROWS);

	print_map(map);

	printf("Err: %d\n", err);
	return 0;
}
