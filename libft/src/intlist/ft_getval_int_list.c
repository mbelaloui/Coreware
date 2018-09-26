/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getval_int_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:31:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:32:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_getval_int_list(const t_int_list *list, const size_t index,
		intmax_t *data)
{
	size_t cp;

	cp = 0;
	if (!list)
		return (F);
	while (cp < index && list)
	{
		list = list->next;
		cp++;
	}
	*data = (list) ? list->data : 0;
	return (T);
}
