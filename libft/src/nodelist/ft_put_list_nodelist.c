/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_list_nodelist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:32:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/14 19:14:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

void	ft_put_list_nodelist(t_nodelist *list)
{
	while (list)
	{
		ft_put_node(list->node);
		list = list->next;
	}
}
