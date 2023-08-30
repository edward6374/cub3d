/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduchi <vduchi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:33:46 by vduchi            #+#    #+#             */
/*   Updated: 2022/05/28 22:06:35 by vduchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*my;

	my = NULL;
	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		my = *lst;
		while (my->next != NULL)
			my = my->next;
		my->next = new;
	}
}
