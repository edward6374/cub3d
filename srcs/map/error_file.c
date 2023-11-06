/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:08:21 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/06 22:26:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "error.h"
#include "libft.h"

int check_file(int argc)
{

	if (argc == 1)
		return (ft_message(DANGER, "Map file name required!"), 1);
	else if (argc > 2)
		return (ft_message(DANGER, "Too many arguments"), 1);
	return (0);
}
