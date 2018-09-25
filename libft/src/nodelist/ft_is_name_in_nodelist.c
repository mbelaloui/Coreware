/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_name_in_nodelist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:10:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/13 10:42:29 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

BOOL	ft_is_name_in_nodelist(char *nom, t_nodelist *list)
{
	while (list)
	{
		if (!ft_strcmp(nom, list->node->name))
			return (T);
		list = list->next;
	}
	return (F);
}
