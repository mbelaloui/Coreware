/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char_in_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:24:17 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 11:32:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_replace_char_in_str(char *str, char rep, char repwith)
{
	char *ret;
	int  len;
	int i;

	ret = NULL;
	if (str && rep && repwith)
	{
		i = 0;
		len = ft_strlen(str);
		ret = ft_strnew(len);
		while (str[i])
		{
			ret[i] = (str[i] == rep) ? repwith : str[i];
			i++;
		}
	}
	return (ret);
}
