/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:05:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/09 16:38:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "colorsft.h"
#include <fcntl.h>

// #include <unistd.h>

int ctrl_path(char **textures)
{
	int i = 0;
	int fd;

	// ft_printf(MAGENTA "%s\n" RESET, getcwd(NULL, sizeof(char *)));
	if (textures)
	{
		while (textures[i])
		{
			fd = open(textures[i], O_RDONLY);
			if (fd >= 0)
			{
				close(fd);
				// return (0);
				ft_printf(GREEN "EXITE: %s\n", textures[i]);
			}
			else
			{
				ft_printf(RED "NO: %s\n", textures[i]);
				// return (1);
			}
			i++;
		}
	}
	return (0);
}
