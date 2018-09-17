/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intervert_head_intlist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:39:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:39:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_intervert_head_intlist(t_int_list **list)
{
	t_int_list *first;
	t_int_list *second;

	if (list && *list && (*list)->next)
	{
		first = *list;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*list = second;
	}
	else
		return (F);
	return (T);
}
