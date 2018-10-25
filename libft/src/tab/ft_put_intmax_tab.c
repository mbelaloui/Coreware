/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_intmax_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:59:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 12:52:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

void	ft_put_intmax_tab(intmax_t *tab, size_t size)
{
	size_t	pt;

	pt = 0;
	ft_printf("tab {");
	size /= sizeof(intmax_t);
	while (pt < size)
	{
		if (pt + 1 < size)
			ft_printf("%d, ", tab[pt++]);
		else
			ft_printf("%d", tab[pt++]);
	}
	ft_printf("}.\n");
}
