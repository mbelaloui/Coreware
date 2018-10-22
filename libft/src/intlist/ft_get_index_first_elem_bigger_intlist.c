/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_first_elem_bigger_intlist.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:40:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 14:37:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

/*
**    input  ->    const list , val of comparison
**    output ->    index of the first element superior to $val
**    error  ->    if (is_empty (list))  -> -1
**                 if max(list) < ($val) -> -1
**    interval of return ->  [0,   size_list - 1]
*/

int		ft_get_index_first_elem_bigger_intlist(const t_int_list *list,
		const intmax_t val)
{
	intmax_t index;

	if (list)
	{
		index = 0;
		while (list)
		{
			if (list->data > val)
				return (index);
			index++;
			list = list->next;
		}
	}
	return (-1);
}
