/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_father.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:18:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:47:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

t_int_list		*ft_get_father(int id_end, t_nodelist *listnode)
{
	t_int_list *list_id_father;

	list_id_father = NULL;
	while (listnode)
	{
		if (ft_is_in_intlist(id_end, listnode->node->list_neighbors))
			ft_add_end_intlist(listnode->node->id, &list_id_father);
		listnode = listnode->next;
	}
	return (list_id_father);
}
