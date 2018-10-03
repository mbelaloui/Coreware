/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:25:46 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:47:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mem.h"

void	*ft_memchr(const void *str, int c, size_t max_size)
{
	size_t			pt;
	unsigned char	*temp_s;

	temp_s = (unsigned char *)str;
	pt = 0;
	while (pt < max_size)
	{
		if (temp_s[pt] == (unsigned char)c)
			return (&temp_s[pt]);
		pt++;
	}
	return (NULL);
}
