/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:09:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/06 16:17:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_getword(const char *str, const int idword, const char separator)
{
	char	*result;
	size_t	pt_w;
	size_t	lenword;

	if (!str || idword < 0)
		return (NULL);
	if ((int)(pt_w = ft_getfirstindexword(str, idword, separator)) < 0)
		return (NULL);
	lenword = ft_getlenword(str, pt_w, separator);
	result = ft_strcut(str, pt_w, (pt_w + lenword));
	result[lenword++] = '\0';
	return (result);
}
