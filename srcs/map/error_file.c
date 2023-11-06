/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:08:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/06 20:52:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int check_file(int argc, char *argv[])
{
	(void)argv;

	if (argc == 1)
		return (ft_printf("Map file name required!\n"), 1);
	else if (argc > 3)
		return (ft_printf("Too many arguments\n"), 1);
	return (0);
}
