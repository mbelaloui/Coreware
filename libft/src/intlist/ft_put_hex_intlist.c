/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_intlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:21:12 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 13:21:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	ft_put_hex_intlist(const t_int_list *list)
{
	if (ft_is_empty_intlist(list))
		ft_printf("[∅].\n");
	else
	{
		ft_printf("[");
		while (list)
		{
			ft_printf("%.2x", (unsigned char)list->data);
			list = list->next;
			if (list)
				ft_printf(",");
		}
		ft_printf("].\n");
	}
}
