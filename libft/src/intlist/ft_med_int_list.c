/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:13:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/30 19:21:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_med_int_list(t_int_list *list, long double *med)
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
