/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:27:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:30:11 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_min_int_list(const t_int_list *list, intmax_t *min)
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
