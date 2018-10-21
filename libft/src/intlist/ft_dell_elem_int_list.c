/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_elem_int_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:55:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 14:00:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_dell_elem_int_list(intmax_t nbr, t_int_list **list)
{
	t_int_list*pt;
	t_int_list*pt_save;

	if (!*list)
		return (F);
	pt_save = NULL;
	pt = *list;
	while (pt)
	{
		if (pt->data == nbr)
		{
			pt_save->next = pt->next;
			free(pt);
			pt = pt_save->next;
		}
		else
		{
			pt_save = pt;
			pt = pt->next;
		}
	}
	return (T);
}
