/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort_intlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:30:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:45:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

void	ft_mergesort_intlist(t_int_list **list, int size)
{
	intmax_t	*temp_tab;

	temp_tab = ft_intmax_list_to_tab(*list);
	ft_mergesort_tab(temp_tab, size);
	ft_clear_intlist(list);
	*list = ft_tab_to_intlist(temp_tab, sizeof(temp_tab) * size);
	free(temp_tab);
}
