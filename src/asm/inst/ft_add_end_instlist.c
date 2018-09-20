/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end_instlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:13:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 12:53:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

BOOL	ft_add_end_instlist(t_inst *inst, t_instlist **list)
{
	t_instlist	*pt_list;
	t_instlist	*temp;

	if (!inst)
		return (F);
	temp = malloc(sizeof(*temp));
	temp->data = inst;
	temp->next = NULL;
	if (!(*list))
		*list = temp;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp;
	}
	return (T);
}
