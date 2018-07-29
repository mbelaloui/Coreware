/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 03:41:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:34:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strcut(const char *src, const size_t begin, const size_t end)
{
	char	*dest;
	size_t	pt;

	if (src == NULL || begin >= end)
		return (NULL);
	dest = ft_strnew(end - begin);
	if (dest == NULL)
		return (NULL);
	pt = 0;
	while (pt < (end - begin))
	{
		dest[pt] = src[begin + pt];
		pt++;
	}
	return (dest);
}
