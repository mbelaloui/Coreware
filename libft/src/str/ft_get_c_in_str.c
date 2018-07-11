/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c_in_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:30:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/11 16:35:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

int			ft_get_c_in_str(const char *str, const char c)
{
	int index;

	index = 0;
	if (!str || !c)
		return (0);
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (0);
}
