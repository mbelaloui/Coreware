/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 11:59:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 12:50:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

intmax_t	ft_gettab_index(const char *tab, const char val)
{
	intmax_t index;

	if (!tab || !val)
		return (-1);
	index = 0;
	while (tab[index] && tab[index] != val)
		++index;
	if (tab[index] == val)
		return (index);
	return (-1);
}
