/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:20:05 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 15:10:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/node.h"

BOOL	ft_dell_node(t_node **node)
{
	t_int_list	*to_free_list;
	char		*to_free_name;

	if (node && *node)
	{
		to_free_name = (*node)->name;
		ft_strdel(&to_free_name);
		to_free_list = (*node)->list_neighbors;
		ft_clear_intlist(&to_free_list);
		free(*node);
		return (T);
	}
	return (F);
}
