/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:00:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:42:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	int		len;
	int		pt;
	char	*resultat;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	resultat = (char *)ft_strnew(len);
	if (resultat == NULL)
		return (NULL);
	pt = 0;
	while (pt < len)
	{
		resultat[pt] = f((unsigned int)pt, str[pt]);
		pt++;
	}
	resultat[pt] = '\0';
	return ((char *)resultat);
}
