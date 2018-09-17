/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:24:45 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:35:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	int		pt;
	int		length_s1;

	length_s1 = ft_strlen(str);
	result = (char *)ft_strnew(length_s1);
	if (result == NULL)
		return (NULL);
	pt = 0;
	while (str[pt])
	{
		result[pt] = str[pt];
		pt++;
	}
	result[pt] = '\0';
	return ((char *)result);
}
