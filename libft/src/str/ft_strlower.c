/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:19:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:41:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strlower(const char *str)
{
	char	*ret;
	int		pt;

	if (str == NULL)
		return (NULL);
	ret = (char *)str;
	pt = 0;
	while (ret[pt])
	{
		if (ft_isupper(ret[pt]))
			ret[pt] = ret[pt] + ('a' - 'A');
		pt++;
	}
	return (ret);
}
