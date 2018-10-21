/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_stat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:17:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:24:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

void	ft_strdup_stat(const char *src, char *dest)
{
	int		pt;

	if (ft_strlen(src) != ft_strlen(dest))
		return ;
	pt = -1;
	ft_memset(dest, ' ', 8);
	while (src[++pt])
	{
		dest[pt] = src[pt];
	}
}
