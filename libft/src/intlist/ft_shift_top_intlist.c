/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_top_intlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:44:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:44:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_shift_top_intlist(t_int_list **list)
{
	t_int_list *bgn;
	t_int_list *end;

	if (list && *list && (*list)->next)
	{
		bgn = *list;
		while ((*list)->next)
			*list = (*list)->next;
		end = *list;
		*list = bgn->next;
		end->next = bgn;
		bgn->next = NULL;
	}
	else
		return (F);
	return (T);
}
