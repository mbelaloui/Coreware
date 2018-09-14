/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_top_int_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:54:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 14:44:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_shift_top_int_list(t_int_list **list)
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
