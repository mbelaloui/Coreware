/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_int_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 18:17:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 18:18:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

size_t		ft_size_int_list(const t_int_list *list)
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
