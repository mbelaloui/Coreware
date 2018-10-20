/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_found_elem_intlist.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:27:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:28:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

int		ft_get_nbr_found_elem_intlist(const intmax_t e, const t_int_list *list)
{
	int nbr_ret;

	nbr_ret = 0;
	while (list)
	{
		if (list->data == e)
			nbr_ret++;
		list = list->next;
	}
	return (nbr_ret);
}
