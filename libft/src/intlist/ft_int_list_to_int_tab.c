/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_list_to_int_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:34:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 14:53:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

intmax_t		*ft_int_list_to_int_tab(t_int_list *list)
{
	intmax_t	*tab;
	int			size;

	size = ft_size_intlist(list);
	if (!(tab = malloc(sizeof(*tab) * size)))
		return (NULL);
	size = 0;
	while (list)
	{
		tab[size] = list->data;
		list = list->next;
		size++;
	}
	return (tab);
}
