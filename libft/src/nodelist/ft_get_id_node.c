/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_id_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:38:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/13 10:41:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

int		ft_get_id_node(char *node_name, t_nodelist *listnode)
{
	int ret;

	ret = -1;
	while (listnode && ft_strcmp(node_name, listnode->node->name))
		listnode = listnode->next;
	if (listnode)
		ret = listnode->node->id;
	return (ret);
}
