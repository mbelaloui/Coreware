/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr_found_elem_int_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:38:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:54:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

int		ft_getnbr_found_elem_int_list(const intmax_t e, const t_int_list *list)
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
