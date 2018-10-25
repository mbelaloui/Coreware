/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_taken_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:08:56 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:59:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

void	ft_set_taken_room(int id_room, t_nodelist *listants)
{
	while (listants)
	{
		if (listants->node->id == id_room)
		{
			listants->node->stats = TAKEN;
			break ;
		}
		listants = listants->next;
	}
}
