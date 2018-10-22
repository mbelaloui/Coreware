/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_to_charlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:13:07 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 17:50:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

t_charlist	*ft_mat_to_charlist(char **mat)
{
	t_charlist	*ret;
	int			i;

	i = 0;
	if (!mat)
		return (NULL);
	ret = NULL;
	while (mat[i])
	{
		ft_add_charlist(mat[i], &ret);
		i++;
	}
	return (ret);
}
