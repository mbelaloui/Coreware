/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intervert_head_int_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:50:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/18 12:46:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_intervert_head_int_list(t_int_list **list)
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
