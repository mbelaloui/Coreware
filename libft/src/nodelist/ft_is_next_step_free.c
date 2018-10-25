/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_next_step_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:05:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:07:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_is_next_step_free(int pos, t_int_list *path, t_nodelist *listnode,
		int id_end)
{
	int		id_next_room;
	t_node	*node;

	if (id_end == pos)
		return (-1);
	while (path && path->data != pos)
		path = path->next;
	if (!path)
		return (-1);
	path = path->next;
	node = ft_get_node_listnode(listnode, path->data);
	id_next_room = node->id;
	if (node->stats == FREE)
	{
		return (id_next_room);
	}
	return (-1);
}
