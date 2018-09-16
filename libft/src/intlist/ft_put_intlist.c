/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_intlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:42:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:42:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	ft_put_intlist(const t_int_list *list)
{
	if (ft_is_empty_intlist(list))
		ft_printf("[∅].\n");
	else
	{
		ft_printf("[");
		while (list)
		{
			ft_printf("%ld", list->data);
			list = list->next;
			if (list)
				ft_printf(",");
		}
		ft_printf("].\n");
	}
}
