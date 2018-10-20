/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pivot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:39:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/04 20:58:46 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

BOOL	ft_get_pivot(t_int_list *list, int sizelist, intmax_t *ret, int pres)
{
	intmax_t *tab;

	tab = ft_intmax_list_to_tab(list);
	ft_mergesort_tab(tab, sizelist);
	sizelist = sizelist * pres;
	sizelist = sizelist / 100;
	*ret = tab[sizelist];
	free(tab);
	return ((sizelist) ? 1 : 0);
}
