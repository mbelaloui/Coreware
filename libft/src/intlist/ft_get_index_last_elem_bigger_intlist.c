/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_last_elem_bigger_intlist.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:22:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 14:37:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

/*
**    input  ->    const list , val of comparison
**    output ->    index of the last element superior to $val
**    error  ->    if (is_empty (list))  -> -1
**                 if max(list) < ($val) -> -1
**    interval of return ->  [0,   size_list - 1]
*/

int		ft_get_index_last_elem_bigger_intlist(const t_int_list *list,
		const intmax_t val)
{
	intmax_t index;
	intmax_t max_index;

	max_index = -1;
	if (list)
	{
		index = 0;
		while (list)
		{
			if (list->data > val)
				max_index = index;
			index++;
			list = list->next;
		}
	}
	return (max_index);
}
