/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:05:08 by vduchi            #+#    #+#             */
/*   Updated: 2023/08/29 17:42:40 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_uns_to_str(char *str, unsigned int n, int len)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		str[len - i - 1] = ((n % 10) + '0');
		n /= 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

static char	*ft_int_to_str(char *str, long int n, int sign, int len)
{
	int	i;

	i = 0;
	if (sign == 1)
	{
		str[0] = '-';
		n *= -1;
		len--;
	}
	while (n > 0)
	{
		str[len + sign - i - 1] = ((n % 10) + '0');
		n /= 10;
		i++;
	}
	str[len + sign] = '\0';
	return (str);
}

static int	ft_count(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*str;

	sign = 0;
	len = ft_count((long int)n);
	if (len == 0)
		str = ft_strdup("0");
	else
	{
		if (n < 0)
			sign = 1;
		str = ft_calloc(sizeof(char), len + 1);
		if (!str)
			return (NULL);
		str = ft_int_to_str(str, (long int)n, sign, len);
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	cpy;

	len = 0;
	cpy = n;
	while (cpy > 0)
	{
		len++;
		cpy /= 10;
	}
	if (len == 0)
		str = ft_strdup("0");
	else
	{
		str = ft_calloc(sizeof(char), len + 1);
		if (!str)
			return (NULL);
		str = ft_uns_to_str(str, (unsigned long int)n, len);
	}
	return (str);
}
