/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_indirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:32:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/05 13:07:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_str_indirect(char *arg)
{
//		ft_printf("{yellow}is indirect{eoc}\n");
	if (arg[0] == LABEL_CHAR)
	{
//		ft_printf("{yellow}is label {eoc}\n");
			return (ft_is_str_label_param(arg + 1));
	}
	else if (ft_isnumerique(arg))
		return (T);
	return (F);
}
