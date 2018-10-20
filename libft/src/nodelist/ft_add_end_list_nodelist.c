/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end_list_nodelist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:30:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/13 10:40:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_add_end_list_nodelist(t_node *node, t_nodelist **list)
{
	t_nodelist		*temp_node;
	t_nodelist		*pt_list;

	if (!node || !(temp_node = ft_new_nodelist(node)))
		return (F);
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
