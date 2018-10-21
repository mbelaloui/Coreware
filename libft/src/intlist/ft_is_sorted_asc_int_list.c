/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted_asc_int_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:38:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:54:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_is_sorted_asc_int_list(const t_int_list *list)
{
	if (!list || !list->next)
		return (T);
	while (list->next)
	{
		if (list->data > (list->next)->data)
			return (F);
		list = list->next;
	}
	return (T);
}
