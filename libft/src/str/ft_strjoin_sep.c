/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:27:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 16:15:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strjoin_sep(char const *str1, char const *str2, const char c)
{
	char	*result;
	int		size_ret;

	if (str2)
	{
		size_ret = ft_strlen(str1) + ft_strlen(str2) + 1;
		if (!(result = ft_strnew(size_ret)))
			return (NULL);
		ft_strlcat(result, str1, size_ret);
		result[ft_strlen(str1)] = c;
		ft_strlcat(result, str2, size_ret + 1);
		return (result);
	}
	return (NULL);
}
