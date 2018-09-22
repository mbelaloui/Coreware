/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:26:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:50:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mem.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char *temp_dest;
	unsigned char *temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (dest < src)
		ft_memcpy(dest, src, size);
	else
		while (size--)
			temp_dest[size] = temp_src[size];
	return (dest);
}
