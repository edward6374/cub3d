/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:34:53 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/12 12:21:25 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "libft.h"
#include "colorsft.h"

void	add_lst(t_char **lst, t_char *new)
{
	t_char	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	init_colors(char **file, t_img *img)
{
	int		i;
	int		ch;
	int		len;
	t_char	*new;

	i = 0;
	len = 0;
	ch = img->measures[CHAR];
	while (file[i])
	{
		if (file[i][ch + 2] == 'c' && file[i][ch + 3] == ' ')
		{
			len = ft_strlen(file[i]) - (ch + 7);
			new = (t_char *)malloc(sizeof(t_char));
			new->chars = ft_substr(file[i], 1, ch);
			new->hex_color = ft_substr(file[i], ch + 4, len);
			hex_to_rgb(new->hex_color, &(new->rgb.r), &(new->rgb.g), \
				&(new->rgb.b));
			new->next = NULL;
			add_lst(&(img->lst), new);
		}
		i++;
	}
}
