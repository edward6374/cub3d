/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:34:53 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/30 16:38:12 by nmota-bu         ###   ########.fr       */
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

	while (file[i])
	{
		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
		{
			// printf(YELLOW "ORIGINAL: %s" RESET, file[i]);

			len = ft_strlen(file[i]) - (ch + 7);
			new = (t_char *)malloc(sizeof(t_char));
			new->chars = ft_substr(file[i], 1, ch);
			new->hex_color = ft_substr(file[i], ch + 4, len);
			hex_to_rgb(new->hex_color, &(new->rgb.r), &(new->rgb.g), &(new->rgb.b));

			new->next = NULL;
			add_lst(&(img->lst), new);
		}
		i++;
	}
}
