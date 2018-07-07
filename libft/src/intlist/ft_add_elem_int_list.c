/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_elem_int_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:16:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 13:29:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_add_elem_int_list(int index, intmax_t nbr, t_int_list **list)
{
	int			size;
	int			cp;
	t_int_list	*temp;
	t_int_list	*head;

	head = *list;
	if (index == 0)
	{
		ft_add_bgn_intlist(nbr, list);
		return (T);
	}
	size = ft_size_intlist(*list);
	if (index > size)
		return (F);
	cp = -1;
	while (++cp < index)
	{
		temp = (*list);
		(*list) = (*list)->next;
	}
	temp->next = ft_new_intlist(nbr);
	(temp->next)->next = *list;
	*list = head;
	return (T);
}
