/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_list_intlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:42:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 12:43:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_cp_list_intlist(t_int_list *src, t_int_list **dest)
{
	t_int_list *temp_dest;

	temp_dest = *dest;
	if (!src || !dest)
		return (F);
	while (src)
	{
		ft_add_end_intlist(src->data, &temp_dest);
		src = src->next;
	}
	*dest = temp_dest;
	return (T);
}
