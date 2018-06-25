/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_bgn_intlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:29:05 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:34:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_add_bgn_intlist(intmax_t nbr, t_int_list **list)
{
	t_int_list *temp_node;

	if (!(temp_node = ft_new_intlist(nbr)))
		return (F);
	if (ft_is_empty_intlist(*list))
		*list = temp_node;
	else
	{
		temp_node->next = *list;
		*list = temp_node;
	}
	return (T);
}
