/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_champ_champlist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:18:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:20:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_champ_champlist(t_champ *champ, t_listchamp **list)
{
	t_listchamp*temp_node;
	t_listchamp*pt_list;

	ft_printf("{yellow}%s{eoc}", champ->name);
	if (!(temp_node = ft_new_listchamp(champ)) )// || !list)
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if (!(*list))
		*list = temp_node;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp_node;
	}
	return (T);
}
