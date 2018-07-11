/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_list_charlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:34:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/11 15:44:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

BOOL	ft_dell_list_charlist(t_charlist **to_free)
{
	t_charlist *pt;

	if (!to_free || !(*to_free))
		return (F);
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		*to_free = (*to_free)->next;
		ft_dell_charlist(&pt);
	}
	*to_free = NULL;
	return (T);
}
