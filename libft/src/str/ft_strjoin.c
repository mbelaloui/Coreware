/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:52:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 11:30:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

/*
** if (str1 && str2)
**  {
**  }
** return (NULL);
*/

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*result;

	if (str1 && str2)
	{
		result = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
		if (result == NULL)
			return (NULL);
		ft_strcat(result, str1);
		ft_strcat(result, str2);
	}
	else
		return ((str1) ? ft_strdup(str1) : ft_strdup(str2));
	return (result);
}
