/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:54:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:45:00 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

int		ft_strncmp(const char *str1, const char *str2, size_t max_cp)
{
	size_t		pt;

	pt = 0;
	while (((unsigned char)*str1 || (unsigned char)*str2) && (pt < max_cp))
	{
		if ((unsigned char)*str1 != (unsigned char)*str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
		pt++;
	}
	return (0);
}
