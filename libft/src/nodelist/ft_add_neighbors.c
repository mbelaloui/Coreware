/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_neighbors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:39:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:46:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

void	ft_add_neighbors(t_nodelist *listnode, char *node_name, char *neighbor)
{
	int	id_neighbor;

	id_neighbor = ft_get_id_node(neighbor, listnode);
	while (listnode && ft_strcmp(node_name, listnode->node->name))
		listnode = listnode->next;
	if (listnode
			&& !ft_is_in_intlist(id_neighbor, listnode->node->list_neighbors))
		ft_add_end_intlist(id_neighbor, &listnode->node->list_neighbors);
}
