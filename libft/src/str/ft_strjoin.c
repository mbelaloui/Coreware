/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:52:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:39:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

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
		return (result);
	}
	return (NULL);
}
