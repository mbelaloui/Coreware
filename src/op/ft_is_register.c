/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_register.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:37:54 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 13:55:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_register(char *arg)
{
	int id_reg;

	if (arg[0] == REGISTRE_CHAR)
	{
		if (ft_isdigit(arg[1]) && ft_isnumerique(arg + 1))
		{
			id_reg = ft_atoi(arg + 1);
			if (!id_reg || id_reg > REG_NUMBER)
				return (F);
			else
				return (T);
		}
		else
			return (F);
	}
	return (F);
}
