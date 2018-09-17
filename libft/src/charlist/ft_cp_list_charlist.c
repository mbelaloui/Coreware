/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_list_charlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:09:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 12:10:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

BOOL	ft_cp_list_charlist(t_charlist *src, t_charlist **dest)
{
	t_charlist *temp_dest;

	temp_dest = *dest;
	if (!src || !dest)
		return (F);
	while (src)
	{
		ft_add_charlist(src->data, &temp_dest);
		src = src->next;
	}
	*dest = temp_dest;
	return (T);
}
