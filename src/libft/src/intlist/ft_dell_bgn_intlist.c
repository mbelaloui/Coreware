/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_bgn_intlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:35:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:45:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_dell_bgn_intlist(t_int_list **list)
{
	t_int_list	*to_free;

	if ((*list) == NULL)
		return (F);
	to_free = *list;
	if (!(*list)->next)
		*list = NULL;
	else
		*list = (*list)->next;
	free(to_free);
	return (T);
}
