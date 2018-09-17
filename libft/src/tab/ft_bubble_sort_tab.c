/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:20:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/22 15:16:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

void	ft_bubble_sort_tab(intmax_t *tab, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap_int(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
