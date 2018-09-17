/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:11:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:53:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*retour;
	int		pt;

	retour = (void *)NULL;
	pt = 0;
	while (str[pt])
	{
		if (str[pt] == c)
			retour = (char *)&str[pt];
		pt++;
	}
	if (c == '\0')
		return ((char *)&str[pt]);
	return ((char *)retour);
}
