/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:57:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/16 18:30:31 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

static void	clear(char **str1, char **str2, int del)
{
	if (*str1 && (del == FIRST || del == BOTH))
		ft_strdel(str1);
	if (*str2 && (del == SECOND || del == BOTH))
		ft_strdel(str2);

}

char		*ft_strjoin_clear(char **str1, char **str2, int del)
{
	char	*result;

	result =  NULL;
	if (*str1 && *str2)
	{
		result = ft_strnew(ft_strlen(*str1) + ft_strlen(*str2));
		if (result == NULL)
			return (NULL);
		ft_strcat(result, *str1);
		ft_strcat(result, *str2);
	}
	else
		result  = ((*str1) ? ft_strdup(*str1) : ft_strdup(*str2));
	clear(str1, str2, del);
	return (result);
}
