/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_int_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:39:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:53:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_is_in_int_list(const intmax_t e, const t_int_list *list)
{
	while (list)
	{
		if (list->data == e)
			return (T);
		list = list->next;
	}
	return (F);
}
