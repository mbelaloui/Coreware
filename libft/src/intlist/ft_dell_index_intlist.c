/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_index_intlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:27:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:45:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_dell_index_intlist(int index, t_int_list **list)
{
	int			cp;
	t_int_list	*pt;
	t_int_list	*pt_save;

	if (!*list || index < 0)
		return (F);
	if (!index)
		return (ft_dell_bgn_intlist(list));
	pt_save = NULL;
	pt = *list;
	cp = 0;
	while (pt && cp < index)
	{
		pt_save = pt;
		pt = pt->next;
		cp++;
	}
	if (!pt)
		return (F);
	pt_save->next = pt->next;
	free(pt);
	pt = pt_save;
	return (T);
}
