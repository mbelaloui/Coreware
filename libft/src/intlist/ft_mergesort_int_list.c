/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort_int_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:31:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/31 14:50:46 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

void	ft_mergesort_int_list(t_int_list **list, int size)
{
	intmax_t	*temp_tab;

	temp_tab = ft_intmax_list_to_tab(*list);
	ft_mergesort_tab(temp_tab, size);
	ft_clear_int_list(list);
	*list = ft_tab_to_int_list(temp_tab, sizeof(temp_tab) * size);
	free(temp_tab);
}
