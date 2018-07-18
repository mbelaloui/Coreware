/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_charlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:25:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 11:28:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

t_charlist	*ft_str_to_charlist(char *str, char sep)
{
	t_charlist	*ret;
	char		**temp;
	int			i;

	i = 0;
	if (!ft_strlen(str))
		return (NULL);
	temp = ft_strsplit(str, sep);
	ret = NULL;
	while (temp[i])
	{
		ft_add_charlist(temp[i], &ret);
		i++;
	}
	ft_free_mat(&temp);
	return (ret);
}
