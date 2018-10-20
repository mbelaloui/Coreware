/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_intlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:31:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:31:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_min_intlist(const t_int_list *list, intmax_t *min)
{
	if (!list)
		return (F);
	*min = list->data;
	while (list)
	{
		if (list->data < *min)
			*min = list->data;
		list = list->next;
	}
	return (T);
}
