/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:31:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:46:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strncpy(char *dst, const char *src, size_t max_cpy)
{
	size_t pt;

	pt = 0;
	while (src[pt] && (pt < max_cpy))
	{
		dst[pt] = src[pt];
		pt++;
	}
	while (pt < max_cpy)
		dst[pt++] = '\0';
	return ((char *)dst);
}
