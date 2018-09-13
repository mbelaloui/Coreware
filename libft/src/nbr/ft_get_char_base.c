/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:18:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:35:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

int		ft_get_char_base(const char nbr)
{
	char	*elem_base;
	int		val;

	val = 0;
	elem_base = "0123456789abcdef";
	while (val < 16)
	{
		if (elem_base[val] == nbr)
			return (val);
		val++;
	}
	return (val);
}
