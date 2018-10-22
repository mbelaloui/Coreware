/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_intlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:19:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/30 19:21:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

size_t		ft_size_intlist(const t_int_list *list)
{
	size_t size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
