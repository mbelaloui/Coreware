/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_id_best_father.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:20:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 15:34:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

intmax_t	ft_get_id_best_father(t_int_list *list_fathers,
		t_nodelist *listnode)
{
	intmax_t	best_dist;
	intmax_t	best_id;
	t_node		*temp_node;

	if (!list_fathers)
		return (-1);
	temp_node = ft_get_node_listnode(listnode, list_fathers->data);
	best_dist = temp_node->dist;
	best_id = temp_node->id;
	list_fathers = list_fathers->next;
	while (list_fathers && best_dist)
	{
		temp_node = ft_get_node_listnode(listnode, list_fathers->data);
		if (temp_node->dist < best_dist && temp_node->dist >= 0)
		{
			best_id = temp_node->id;
			best_dist = temp_node->dist;
		}
		list_fathers = list_fathers->next;
	}
	return (best_id);
}
