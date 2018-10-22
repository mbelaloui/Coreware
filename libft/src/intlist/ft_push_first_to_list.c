/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_first_to_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:59:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 14:51:00 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_push_first_to_list(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	*save_head_list_b;

	if (!list_a || !list_b || !(*list_a))
		return (F);
	save_head_list_b = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->next;
	(*list_b)->next = save_head_list_b;
	return (T);
}
