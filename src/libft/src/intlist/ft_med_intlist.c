/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med_intlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:30:48 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:30:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_med_intlist(t_int_list *list, long double *med)
{
	intmax_t	*temp_tab;
	int			size;

	if (!list)
		return (F);
	size = ft_size_intlist(list);
	temp_tab = ft_intmax_list_to_tab(list);
	ft_mergesort_tab(temp_tab, size);
	*med = 0;
	if (size % 2)
		*med = temp_tab[(size / 2)];
	else
		*med = (temp_tab[size / 2] + temp_tab[(size / 2) + 1]) / 2;
	return (T);
}
