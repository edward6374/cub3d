/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:05:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/11/11 01:16:21 by nmota-bu         ###   ########.fr       */
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

	if (textures)
	{
		while (textures[i])
		{
			fd = open(textures[i], O_RDONLY);
			if (fd >= 0)
				close(fd);
			else if (fd <= 0)
			{
				err = 1;
				ft_message(DANGER, "Eror");
				ft_message(DANGER, "Wrong path: ");
				ft_message(INFO, textures[i]);
			}
			i++;
		}
	}
	return (err);
}
