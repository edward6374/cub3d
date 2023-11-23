/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:39:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/23 12:19:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colorsft.h"
#include "cub3d.h"
#include "error.h"

void check_num(int r, int g, int b)
{
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
	{
		ft_message(DANGER, "Error\nThe color is not within RBG.");
		exit(EXIT_FAILURE);
	}
}

void is_num(char *str)
{
	int i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
		{
			ft_message(DANGER, "Error");
			ft_printf(CYAN "The character: '%c' cannot be on RGB.\n" RESET, str[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char *ft_split_join_plus(char **split)
{
	int i;
	char *res;

	i = 1;
	res = NULL;
	while (split[i])
	{
		is_num(split[i]);
		if (res == NULL)
			res = ft_strdup(split[i]);
		else
			res = ft_strjoin(res, split[i]);
		i++;
	}
	return (res);
}

void init_color(t_color *color, char *split)
{
	char **rgb;
	int r;
	int g;
	int b;
	rgb = ft_split(split, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	check_num(r, g, b);
	color->r = r;
	color->g = g;
	color->b = b;
	free(rgb);
}

void check_rgb(t_color *color, char **split)
{
	int i;

	i = 0;
	char *res;
	res = NULL;

	if (ft_len_dptr(split) > 2)
	{
		res = ft_split_join_plus(split);
		init_color(color, res);
	}
	else
		init_color(color, split[1]);
	free(res);
}
