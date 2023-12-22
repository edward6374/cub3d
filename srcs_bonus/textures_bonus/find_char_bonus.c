/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_char_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:46:53 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/22 15:17:30 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d_bonus.h"
#include "libft.h"

// TODO
// SELE PASA X(0-63) Y(0-63)

char	*find_char(t_img *img, int x, int y)
{
	char	*res;

	res = malloc((img->measures[CHAR] + 1) * sizeof(char));
	if (img->measures[CHAR] == 1)
	{
		res[0] = img->img[x][y + 1];
		res[1] = '\0';
	}
	else if (img->measures[CHAR] != 1)
	{
		res[0] = img->img[x][(y * img->measures[CHAR]) + 1];
		res[1] = img->img[x][(y * img->measures[CHAR]) + 2];
		res[2] = '\0';
	}
	return (res);
}

t_color	*find_rgb(t_char *lst, char *chars, int n)
{
	t_char	*tmp;
	t_color	*found;

	tmp = lst;
	found = NULL;
	while (tmp != NULL)
	{
		if (!ft_strncmp(tmp->chars, chars, n))
		{
			found = &tmp->rgb;
			return (found);
		}
		tmp = tmp->next;
	}
	return (found);
}
