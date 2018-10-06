/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:22:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/06 12:26:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_champ(t_champ *champ, t_champ **list)
{
	t_champ		*pt_list;

	if (!list || !champ)
		return (F);
	if (!(*list))
		*list = champ;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = champ;
	}
	return (T);
}

/*
//	t_int_list *temp_node;

	if (!champ || !list)
		return (F);
	if (!(*list))
		*list = champ;
	else
	{
		champ->next = *list;
		*list = champ;
	}
	return (T);
}*/