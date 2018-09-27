/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_bottom_int_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:52:52 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/08 19:21:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_shift_bottom_int_list(t_int_list **list)
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
