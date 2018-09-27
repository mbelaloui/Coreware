/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_str_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:09:42 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:48:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_u_str_to_str(unsigned char str[4])
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(4);
	while (i < 4)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}
