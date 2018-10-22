/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_somme_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:17:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 17:10:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

int			ft_somme_tab(int *tab, int size)
{
	int somme;
	int pt;

	pt = 0;
	somme = 0;
	while (pt < size)
	{
		somme += tab[pt];
		pt++;
	}
	return (somme);
}
