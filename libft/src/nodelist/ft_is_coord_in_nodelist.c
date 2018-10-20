/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_coord_in_nodelist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:42:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/13 10:41:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_is_coord_in_nodelist(int x, int y, t_nodelist *list)
{
	while (list)
	{
		if (list->node->x == x && list->node->y == y)
			return (T);
		list = list->next;
	}
	return (F);
}
