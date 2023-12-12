/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:13:07 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/12/12 12:21:51 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "colorsft.h"
#include <fcntl.h>

char	**load_img(char *path)
{
	int		fd;
	char	**file_content;

	fd = open(path, O_RDONLY);
	file_content = ft_file_to_dptr_m(fd);
	close(fd);
	return (file_content);
}

void	init_measures(char *num, int measures[])
{
	int		i;
	char	*result;
	char	**split;

	i = -1;
	result = remove_quotes(num);
	split = ft_split(result, ' ');
	free(result);
	while (split[++i])
		measures[i] = ft_atoi(split[i]);
	ft_free_dptr(split);
}

int	get_start(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i], "/* pixels */\n", 13))
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	get_img(char **file, t_img *img)
{
	int	i;
	int	start;

	i = 0;
	start = get_start(file);
	img->img = malloc(sizeof(char *) * img->measures[ROWS] + 1);
	while (file[start])
	{
		img->img[i] = ft_strdup(file[start]);
		i++;
		start++;
	}
	img->img[i] = NULL;
}

void	init_img(t_img img[])
{
	int		i;
	char	**file_content;

	i = 0;
	while (i < 4)
	{
		file_content = load_img(img[i].path);
		init_measures(file_content[3], img[i].measures);
		init_colors(file_content, &img[i]);
		get_img(file_content, &(img[i]));
		ft_free_dptr(file_content);
		i++;
	}
}
