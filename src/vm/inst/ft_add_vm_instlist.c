/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_vm_instlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:36:22 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 13:39:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_vm_instlist(t_int_list *src, t_vm_inst **list)
{
	t_vm_inst*temp_node;
	t_vm_inst*pt_list;

	if (!(temp_node = ft_new_vm_inst(src)))
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
