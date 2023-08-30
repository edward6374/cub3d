/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:35:50 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/29 17:42:28 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_num(unsigned int u, int i, int *count)
{
	char	*str;

	if (!i)
		str = ft_utoa(u);
	else
		str = ft_itoa(i);
	if (!str)
		return (0);
	if (write (1, str, ft_strlen(str)) != (ssize_t)ft_strlen(str))
	{
		free(str);
		return (0);
	}
	*count = *count + ft_strlen(str);
	free(str);
	return (1);
}

int	ft_print_str(char *str, int mode, int *count)
{
	size_t	len;

	if (!str)
	{
		str = NULL;
		if (write (1, "(null)", 6) != 6)
			return (0);
		*count = *count + 6;
		return (1);
	}
	len = ft_strlen(str);
	*count = *count + len;
	if (mode)
	{
		if (write (1, str, len) != (ssize_t)len)
			return (0);
	}
	else
	{
		while (len-- > 0)
			if (write (1, &str[len], 1) != 1)
				return (0);
	}
	return (1);
}

int	ft_print_char(char c, int *count)
{
	if (write (1, &c, 1) != 1)
		return (0);
	*count = *count + 1;
	return (1);
}
