/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_val_intlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:11:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/29 15:41:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

/*
**    input  ->    const list,  index of elem, pointer of intmax_t to retu data
**    output ->    value in *data
**    error  ->    if (is_empty (list))  ->  -1  dont change the value of *data
**           ->    if (index < 0)        ->  -1  dont change the value of *data
**    interval of return ->  x in [list]
*/

BOOL	ft_get_val_intlist(const t_int_list *list, const int index,
		intmax_t *data)
{
	int cp;

	cp = 0;
	if (!list || index < 0)
		return (F);
	while (list && cp < index)
	{
		list = list->next;
		cp++;
	}
	if (list)
	{
		*data = list->data;
		return (T);
	}
	return (F);
}
