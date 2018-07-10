/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_bgn_int_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:23:54 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/10 17:12:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_dell_bgn_int_list(t_int_list **list)
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
