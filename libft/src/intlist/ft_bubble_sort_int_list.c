/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_int_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:17:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/22 13:19:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

void	ft_bubble_sort_int_list(t_int_list **list)
{
	t_int_list *pt_i;
	t_int_list *pt_j;

	pt_i = *list;
	while (pt_i)
	{
		pt_j = pt_i;
		while (pt_j)
		{
			if (pt_i->data > pt_j->data)
				ft_swap_int(&pt_i->data, &pt_j->data);
			pt_j = pt_j->next;
		}
		pt_i = pt_i->next;
	}
}
