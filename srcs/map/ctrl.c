/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:05:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/11 00:48:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "colorsft.h"
#include <fcntl.h>

#include <unistd.h>

int ctrl_path(char **textures)
{
	int i = 0;
	int fd;
	int err = 0;

	// ft_printf(MAGENTA "%s\n" RESET, getcwd(NULL, sizeof(char *)));
	// char *path = getcwd(NULL, sizeof(char *));
	// printf("%s\n", ft_strjoin(path, textures[i]));

	if (textures)
	{
		while (textures[i])
		{

			// ft_printf(CYAN "%s" RESET, textures[i]);
			// // if (access(ft_strjoin(path, textures[i]), F_OK) != -1)
			// if (access(textures[i], F_OK) != -1)
			// 	printf(GREEN "SIII.\n" RESET);
			// else
			// {
			// 	err = 1;
			// 	printf(RED "El archivo no existe.\n" RESET);
			// }
			fd = open(textures[i], O_RDONLY);
			if (fd >= 0)
			{
				// ft_printf(GREEN "EXITE: %d %s\n" RESET, i, textures[i]);
				close(fd);
				// return (0);
			}
			else if (fd <= 0)
			{
				err = 1;
				// close(fd);
				// exit(1);
			}
			ft_printf(GREEN "%d fd:%d %s\n" RESET, i, fd, textures[i]);

			i++;
		}
	}
	return (err);
}
