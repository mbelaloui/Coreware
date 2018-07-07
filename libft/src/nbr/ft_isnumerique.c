/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumerique.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:39:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/14 13:35:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

BOOL	ft_isnumerique(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		if ((str[i] == '+' || str[i] == '-') && (ft_isdigit(str[i + 1])))
			i++;
		while (ft_isdigit(str[i]))
			i++;
		return ((!ft_isalpha(str[i])
					&& (str[i] == 0 || ft_isdigit(str[i]))) ? T : F);
	}
	return (F);
}
