/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_bgn_nodelist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:36:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/18 20:11:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_dell_bgn_nodelist(t_nodelist **list)
{
	t_nodelist	*to_free;

	if ((*list) == NULL)
		return (F);
	to_free = *list;
	if (!(*list)->next)
		*list = NULL;
	else
		*list = (*list)->next;
	ft_dell_node(&(to_free->node));
	free(to_free);
	return (T);
}
