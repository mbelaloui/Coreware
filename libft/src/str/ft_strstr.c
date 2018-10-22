/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:46:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:27:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strstr(const char *h, const char *ne)
{
	int		pt1;
	int		pt2;

	pt1 = 0;
	if (!ft_strlen(ne))
		return ((char *)h);
	while (h[pt1])
	{
		pt2 = 0;
		while ((h[pt1 + pt2]) && ne[pt2] && (h[pt1 + pt2] == ne[pt2]))
			pt2++;
		if (!ne[pt2])
			return ((char *)&h[pt1]);
		pt1++;
	}
	return (NULL);
}
