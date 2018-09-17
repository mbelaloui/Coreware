/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_deep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:12:12 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:46:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL		ft_find_path_deep(t_nodelist *listnodes, t_node *node, t_node *end,
		t_int_list **path)
{
	t_int_list	*list;
	t_node		*temp;

	list = node->list_neighbors;
	if (node->id == end->id)
		return (F);
	node->stats = 1;
	ft_put_node(node);
	while (list)
	{
		temp = ft_get_node_listnode(listnodes, list->data);
		if (temp->stats == 0)
		{
			ft_add_end_intlist(temp->id, path);
			if (ft_find_path_deep(listnodes, temp, end, path))
				return (T);
		}
		list = list->next;
	}
	ft_dell_end_intlist(path);
	return (F);
}
