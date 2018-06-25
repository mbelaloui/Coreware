/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettab_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 11:26:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/04 11:33:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	ft_gettab_val(const char *tab, const int index)
{
	size_t cp;

	if (!tab || index < 0)
		return (0);
	cp = 0;
	while (tab[cp] && ((int)cp < index))
		cp++;
	return (tab[cp] ? tab[cp] : 0);
}
