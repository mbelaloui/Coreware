/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:14:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:13:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

int		ft_fill_elem(int len, char *bit, char *temp_tab, int lim)
{
	int i;

	i = 8;
	while (--i > lim)
	{
		if (len)
			bit[i] = temp_tab[--len];
		else
			bit[i] = '0';
	}
	return (len);
}
