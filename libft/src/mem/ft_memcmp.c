/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:36:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:48:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mem.h"

int		ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*temp_str1;
	unsigned char	*temp_str2;
	size_t			pt;

	temp_str1 = (unsigned char *)str1;
	temp_str2 = (unsigned char *)str2;
	pt = 0;
	while (pt < size)
	{
		if (temp_str1[pt] != temp_str2[pt])
			return (temp_str1[pt] - temp_str2[pt]);
		pt++;
	}
	return (0);
}
