/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reste_status_listnode.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:16:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 14:59:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

void	ft_reste_status_listnode(t_nodelist *listnode)
{
	while (listnode)
	{
		listnode->node->stats = 0;
		listnode = listnode->next;
	}
}
