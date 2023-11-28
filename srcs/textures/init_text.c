/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:13:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/28 14:40:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "libft.h"
#include "colorsft.h"

void init_text(t_param *params)
{
	char **cur;
	(void)params;

	// char **cur = ft_file_to_dptr(params->path[0], 0);
	// cur = ft_file_to_dptr("/Users/nmota-bu/Desktop/cub3d/assets/textures/brow.xpm", 1);
	cur = ft_file_to_dptr("/Users/nmota-bu/Desktop/cub3d/assets/textures/txt.txt", 1);
	// printf("%p\n", tmp);
	// (void)tmp;
	// ft_print_dptr(tmp);
	// printf(RED "%s\n" RESET, tmp[2]);
	// printf("%s\n", params->path[0]);
}
