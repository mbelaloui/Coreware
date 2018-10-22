/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avg_intlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:29:17 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 13:29:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_avg_intlist(const t_int_list *list, long double *avg)
{
	intmax_t size;

	if (!list)
		return (F);
	size = 0;
	*avg = 0;
	while (list)
	{
		*avg += list->data;
		list = list->next;
		size++;
	}
	*avg /= size;
	return (T);
}
