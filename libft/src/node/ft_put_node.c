/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:17:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:46:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/node.h"

void	ft_put_node(t_node *node)
{
	t_int_list *pt_lngbrs;

	ft_printf("id node    : %d\n", node->id);
	ft_printf("name node  : %s\n", node->name);
	ft_printf("stats node : %d\n", node->stats);
	ft_printf("disut node : %d\n", node->dist);
	ft_printf("spacial coordinats [%ld, %ld]\n", node->x, node->y);
	pt_lngbrs = node->list_neighbors;
	if (ft_is_empty_intlist(pt_lngbrs))
		ft_printf("list neighbors {∅}\n");
	else
	{
		ft_printf("id neighbors node {");
		while (pt_lngbrs)
		{
			if (pt_lngbrs->next)
				ft_printf("%ld, ", pt_lngbrs->data);
			else
				ft_printf("%ld", pt_lngbrs->data);
			pt_lngbrs = pt_lngbrs->next;
		}
		ft_printf("}.\n");
	}
	ft_printf("/ ****************************************** \\\n");
}
