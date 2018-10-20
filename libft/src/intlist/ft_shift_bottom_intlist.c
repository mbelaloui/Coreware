/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_bottom_intlist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:42:56 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:43:00 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_shift_bottom_intlist(t_int_list **list)
{
	t_int_list *bgn;
	t_int_list *end;

	if (list && *list && (*list)->next)
	{
		bgn = *list;
		end = *list;
		while ((*list)->next)
		{
			*list = (*list)->next;
			if ((*list)->next)
				end = *list;
		}
		end->next = NULL;
		(*list)->next = bgn;
	}
	else
		return (F);
	return (T);
}
