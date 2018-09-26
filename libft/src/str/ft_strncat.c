/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:12:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:43:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strncat(char *str1, const char *str2, size_t size_max)
{
	size_t	pt;
	int		max_cp;

	pt = ft_strlen(str1);
	max_cp = ft_min((int)size_max, (int)ft_strlen(str2));
	ft_memcpy((str1 + pt), str2, max_cp);
	str1[pt + max_cp] = '\0';
	return ((char *)str1);
}
