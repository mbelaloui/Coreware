/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:22:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 11:33:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL		ft_add_champ(t_champ *champ, t_champ **list)
{
	t_champ	*pt_list;

//	ft_printf("{yellow}%s{eoc}", champ->name);
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
