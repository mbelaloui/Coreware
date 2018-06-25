/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:22:21 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:41:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		len;
	int		pt;
	char	*resultat;

	if (!str || !*f)
		return (NULL);
	len = ft_strlen(str);
	resultat = (char *)ft_strnew(len);
	if (resultat == NULL)
		return (NULL);
	pt = 0;
	while (pt < len)
	{
		resultat[pt] = f(str[pt]);
		pt++;
	}
	resultat[pt] = '\0';
	return ((char *)resultat);
}
