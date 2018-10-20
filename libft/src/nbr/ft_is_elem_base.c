/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_elem_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:48:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:47:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

int		ft_is_elem_base(const char c, const int base)
{
	int		pt;
	char	*elem_base;

	elem_base = "0123456789abcdef";
	pt = -1;
	while (++pt < base)
	{
		if (elem_base[pt] == c)
			return (1);
	}
	return (0);
}
