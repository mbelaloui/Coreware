/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:03:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 19:45:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mat.h"

static char	*mat_to_str(char **argv, int start)
{
	char	*str;
	char	*temp;

	if (!(str = ft_strdup("")))
		return (NULL);
	while (argv[start])
	{
		temp = str;
		if (!(str = ft_strjoin(str, argv[start])))
			return (0);
		ft_strdel(&temp);
		start++;
		if (argv[start])
		{
			temp = str;
			if (!(str = ft_strjoin(str, " ")))
				return (0);
			ft_strdel(&temp);
		}
	}
	return (str);
}

char	*ft_mat_to_str(char **argv, int start)
{
	char	*str;
	char	*temp;

	str = mat_to_str(argv, start);
	temp = str;
	if (!(str = ft_format_str(str)))
		return (NULL);
	ft_strdel(&temp);
	return (str);
}
