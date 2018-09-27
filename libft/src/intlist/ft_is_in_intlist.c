/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_intlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:28:54 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:28:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_is_in_intlist(const intmax_t e, const t_int_list *list)
{
	while (list)
	{
		if (list->data == e)
			return (T);
		list = list->next;
	}
	return (F);
}
