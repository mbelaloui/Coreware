/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 21:03:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/13 19:13:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mat.h"

char	*ft_mat_to_str(char **argv, int start)
{
	char	*str;
	char	*temp;

	str = ft_strdup("");
	while (argv[start])
	{
		temp = str;
		str = ft_strjoin(str, argv[start]);
		ft_strdel(&temp);
		start++;
		if (argv[start])
		{
			temp = str;
			str = ft_strjoin(str, " ");
			ft_strdel(&temp);
		}
	}
	temp = str;
	str = ft_format_str(str);
	ft_strdel(&temp);
	return (str);
}
