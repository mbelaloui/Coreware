/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exist_node_nodelist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:44:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 15:55:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_exist_node_nodelist(t_node *node, t_nodelist *listnodes)
{
	if (ft_is_name_in_nodelist(node->name, listnodes))
		return (T);
	if (ft_is_coord_in_nodelist(node->x, node->y, listnodes))
		return (T);
	return (F);
}
