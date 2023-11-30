/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:34:53 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/30 15:44:49 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "libft.h"
#include "colorsft.h"

void add_lst(t_char **lst, t_char *new)
{
	// (void)lst;
	// printf(RED "\'%s\' " RESET, new->chars);
	// printf(GREEN "%s\n" RESET, new->hex_color);

	t_char *tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void init_colors(char **file, t_img *img)
{
	int ch = img->measures[CHAR];
	int i = 0;
	int len = 0;
	t_char *new;

	printf(MAGENTA "num_colors %d\n" RESET, img->measures[COLORS]);

	while (file[i])
	{
		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
		{

			printf(YELLOW "%s" RESET, file[i]);

			len = ft_strlen(file[i]) - (ch + 7);
			new = (t_char *)malloc(sizeof(t_char));

			// char *charte = ft_substr(file[i], 1, ch);
			// char *hex_color = ft_substr(file[i], ch + 4, len);
			new->chars = ft_substr(file[i], 1, ch);
			new->hex_color = ft_substr(file[i], ch + 4, len);
			new->next = NULL;

			add_lst(&(img->lst), new);

			printf("len: %d ", len);
			// printf(RED "\'%s\' " RESET, charte);
			// printf(GREEN "%s\n" RESET, hex_color);
			printf(RED "\'%s\' " RESET, new->chars);
			printf(GREEN "%s\n" RESET, new->hex_color);

			// free(charte);
			// free(hex_color);
		}
		i++;
	}
}

// void init_colors(char **file, int ch, int num_colors, t_char chears)
// {
// 	int i = 0;
// 	int len = 0;

// 	printf(MAGENTA "num_colors %d\n" RESET, num_colors);

// 	while (file[i])
// 	{
// 		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
// 		{
// 			// printf("%zu\n", ft_strlen(file[i]));
// 			// printf("%d\n", hex_len(file[i]));

// 			printf(YELLOW "%s" RESET, file[i]);

// 			len = ft_strlen(file[i]) - (ch + 7);

// 			// Allocate memory for characters and colors
// 			char *charte = ft_substr(file[i], 1, ch);
// 			char *hex_color = ft_substr(file[i], ch + 4, len);

// 			printf("len: %d ", len);
// 			printf(RED "\'%s\' " RESET, charte);
// 			printf(GREEN "%s\n" RESET, hex_color);

// 			free(charte);
// 			free(hex_color);
// 		}
// 		i++;
// 	}
// }
