/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 01:42:39 by vduchi            #+#    #+#             */
/*   Updated: 2022/05/26 02:25:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		start;
	int		count;
	char	*str;

	i = 0;
	j = 0;
	start = 0;
	str = (char *)s1;
	count = ft_strlen(s1) - 1;
	if (!s1 && !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	while (count > 0 && ft_strchr(set, (int)s1[count]))
		count--;
	str = ft_substr(s1, start, count - start + 1);
	return (str);
}
