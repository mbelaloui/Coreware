/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_room_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:10:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:59:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

void	ft_set_room_free(t_nodelist *listnode, int id)
{
	while (listnode)
	{
		if (listnode->node->id == id)
		{
			listnode->node->stats = FREE;
			break ;
		}
		listnode = listnode->next;
	}
}
