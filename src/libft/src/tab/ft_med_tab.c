/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_med_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:38:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 15:37:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

/*
** pas bien proteger vairdrait mieu paser par celle les intlist
*/

long double		ft_med_tab(intmax_t *tab, size_t size)
{
	long double	med;

	size /= sizeof(intmax_t);
	ft_mergesort_tab(tab, size);
	med = 0;
	if (size % 2)
		med = tab[(size / 2)];
	else
		med = (tab[size / 2] + tab[(size / 2) + 1]) / 2;
	return (med);
}
