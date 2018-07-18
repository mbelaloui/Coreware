/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:15:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 16:55:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

static int	ft_isspase(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r'
			|| c == '\b')
		return (1);
	return (0);
}

char		*ft_format_str(const char *str)
{
	char	*result;
	int		begin;
	int		pt;

	begin = 1;
	pt = 0;
	if (!(result = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (*str)
	{
		if (ft_isspase(*str))
		{
			while (ft_isspase(*str))
				str++;
			if (*str && !begin)
				result[pt++] = ' ';
		}
		else if (*str)
		{
			result[pt++] = *str;
			str++;
		}
		begin = 0;
	}
	return (result);
}
