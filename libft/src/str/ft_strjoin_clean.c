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

char	*ft_strjoin_clear(char *str1, char *str2, int del)
{
	char	*result;

	if (str1 && str2)
	{
		result = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
		if (result == NULL)
			return (NULL);
		ft_strcat(result, str1);
		ft_strcat(result, str2);
		if (del == 1 || del == 3)
			ft_strdel(&str1);
		if (del == 2 || del == 3)
			ft_strdel(&str2);
		return (result);
	}
	return (NULL);
}
