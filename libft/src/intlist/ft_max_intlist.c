/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_intlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:41:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:41:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_max_intlist(const t_int_list *list, intmax_t *max)
{
	if (!list)
		return (F);
	*max = list->data;
	while (list)
	{
		if (list->data > *max)
			*max = list->data;
		list = list->next;
	}
	return (T);
}
