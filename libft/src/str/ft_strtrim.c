/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 03:05:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:56:31 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

static	char	*empty(void)
{
	char *result;

	result = (char *)ft_strnew(0);
	if (result == NULL)
		return (NULL);
	return (result);
}

char			*ft_strtrim(const char *str)
{
	size_t	debut;
	size_t	fin;

	if (!str)
		return (NULL);
	if (ft_isempty(str))
		return (empty());
	debut = 0;
	while (str[debut] && (ft_isblank(str[debut]) || str[debut] == '\n'))
		debut++;
	fin = (ft_strlen(str) - 1);
	while (str[fin] && (ft_isblank(str[fin]) || str[fin] == '\n')
			&& (debut < fin))
		fin--;
	return (ft_strcut(str, debut, fin + 1));
}
