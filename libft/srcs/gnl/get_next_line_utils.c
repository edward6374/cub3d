/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:15:48 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/28 18:06:52 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if ((char)c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s != '\0')
		{
			if (*s == (char)c)
				return ((char *)s++);
			s++;
		}
		return (NULL);
	}
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = -1;
	j = -1;
	count = -1;
	while (s1[++i] != '\0')
		;
	while (s2[++j] != '\0')
		;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	while (++count < (i + j))
	{
		if (count < i)
			str[count] = s1[count];
		else
			str[count] = s2[count - i];
	}
	str[count] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_realloc(char *str, int addr, unsigned int len)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		tmp[i] = str[i + addr];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
