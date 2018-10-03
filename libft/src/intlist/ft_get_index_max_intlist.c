/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_max_intlist.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:33:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:33:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

/*
**    input  ->    const list
**    output ->    index max in list
**    error  ->    if (is_empty (list))  ->  -1
**    interval of return ->  [0,   size_list - 1]
*/

int		ft_get_index_max_intlist(const t_int_list *list)
{
	int			index;
	int			index_max;
	intmax_t	max;

	if (!list)
		return (-1);
	index = 0;
	index_max = 0;
	max = list->data;
	while (list)
	{
		if (list->data > max)
		{
			index_max = index;
			max = list->data;
		}
		list = list->next;
		index++;
	}
	return (index_max);
}
