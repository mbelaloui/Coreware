/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:53:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:40:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size_dest)
{
	size_t pt_end_dest;
	size_t nbr_b_free;

	pt_end_dest = ft_strlen(dest);
	nbr_b_free = size_dest - pt_end_dest;
	if ((int)nbr_b_free <= 0)
		return (size_dest + ft_strlen(src));
	dest = ft_strncat((dest + pt_end_dest), src, nbr_b_free - 1);
	return (pt_end_dest + ft_strlen(src));
}
