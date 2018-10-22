/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:04:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:51:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strnstr(const char *ha, const char *ne, size_t max_comp)
{
	size_t	pt1;
	size_t	pt2;

	pt1 = 0;
	if (!ft_strlen(ne))
		return ((char *)ha);
	while (ha[pt1] && (pt1 < max_comp))
	{
		pt2 = 0;
		while (ha[pt1 + pt2] && ne[pt2] && (ha[pt1 + pt2] == ne[pt2])
				&& ((pt1 + pt2) < max_comp))
			pt2++;
		if (!ne[pt2])
			return ((char *)&ha[pt1]);
		pt1++;
	}
	return (NULL);
}
