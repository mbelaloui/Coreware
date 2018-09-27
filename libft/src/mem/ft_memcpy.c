/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:20:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:48:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mem.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			pt;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	pt = 0;
	while (pt < size)
	{
		temp_dest[pt] = temp_src[pt];
		pt++;
	}
	return (dest);
}
