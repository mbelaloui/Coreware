/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:58:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 12:15:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mem.h"

void	*ft_memset(void *mem, int c, size_t size)
{
	size_t			pt;
	unsigned char	*temp;

	temp = (unsigned char *)mem;
	pt = 0;
	while (pt < size)
	{
		temp[pt] = (unsigned char)c;
		pt++;
	}
	return ((void *)mem);
}
