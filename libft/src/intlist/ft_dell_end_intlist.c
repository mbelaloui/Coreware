/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_end_intlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:35:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:36:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_dell_end_intlist(t_int_list **list)
{
	t_int_list *pt_list;
	t_int_list *pt_sauv;

	if ((*list) == NULL)
		return (F);
	if (!(*list)->next)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		pt_list = *list;
		while (pt_list->next)
		{
			pt_sauv = pt_list;
			pt_list = pt_list->next;
		}
		pt_sauv->next = NULL;
		free(pt_list);
	}
	return (T);
}
