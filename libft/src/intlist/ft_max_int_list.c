/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:30:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:30:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_max_int_list(const t_int_list *list, intmax_t *max)
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
