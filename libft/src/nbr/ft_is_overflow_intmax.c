/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_overflow_intmax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:27:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/19 16:13:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

BOOL	ft_is_overflow_intmax(char *param)
{
	intmax_t	val;
	int			index;
	char		*temp;
	int			signe;
	int			rest;

	if (!param)
		return (F);
	temp = ft_format_str(param);
	index = (temp[0] == '-' || temp[0] == '+') ? 1 : 0;
	signe = (temp[0] == '-') ? 1 : 0;
	val = ft_atointmax(temp);
	while (ft_isdigit(temp[index]))
		index++;
	while (ft_isdigit(temp[--index]))
	{
		rest = (signe) ? -(val % 10) : (val % 10);
		if (temp[index] - '0' == (rest))
			val = val / 10;
		else
			return (ft_strdel(&temp) && T);
	}
	return (ft_strdel(&temp) && F);
}
