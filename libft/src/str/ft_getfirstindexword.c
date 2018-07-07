/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfirstindexword.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:51:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 12:23:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

int	ft_getfirstindexword(const char *str, const int idword, const char c)
{
	int	pt;
	int	cp;

	pt = 0;
	cp = 0;
	if (str == NULL)
		return (-1);
	while (str[pt] && cp <= idword)
	{
		while (str[pt] == c)
			++pt;
		if (str[pt])
			cp++;
		while (cp <= idword && str[pt] && str[pt] != c)
			++pt;
	}
	return ((idword > cp) ? -1 : pt);
}
