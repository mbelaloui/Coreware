/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avg_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:47:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 15:38:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

/*
** printf(" avg tab = %Lf ", avg);
*/

BOOL	ft_avg_tab(const intmax_t *tab, long double *avg, int size)
{
	int		pt;

	*avg = 0;
	pt = -1;
	size /= sizeof(intmax_t);
	while (size--)
		*avg += tab[++pt];
	if (pt < 0)
		return (F);
	*avg /= pt;
	return (T);
}
