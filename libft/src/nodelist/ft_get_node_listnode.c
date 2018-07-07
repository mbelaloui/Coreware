/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node_listnode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:07:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 15:09:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

t_node		*ft_get_node_listnode(t_nodelist *listnode, int id)
{
	int pt;

	pt = 0;
	if (id < 0)
		return (NULL);
	while (listnode && pt < id)
	{
		listnode = listnode->next;
		pt++;
	}
	if (listnode)
		return (listnode->node);
	return (NULL);
}
