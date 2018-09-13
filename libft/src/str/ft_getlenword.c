/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlenword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:49:46 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 12:50:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

size_t	ft_getlenword(const char *str, const int index, const char c)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[index + len] && str[index + len] != c)
		++len;
	return ((size_t)len);
}
