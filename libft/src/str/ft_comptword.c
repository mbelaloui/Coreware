/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comptmot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:48:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/02 13:38:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

size_t	ft_comptword(const char *str, const char separator)
{
	size_t	i;
	size_t	nbrmot;

	nbrmot = 0;
	if (str == NULL)
		return (nbrmot);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == separator)
			i++;
		if (str[i])
			nbrmot++;
		while (str[i] && str[i] != separator)
			i++;
	}
	return (nbrmot);
}
