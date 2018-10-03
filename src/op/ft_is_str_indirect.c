/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_indirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 14:32:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/30 21:07:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_str_indirect(char *arg)
{
	if (arg[0] == LABEL_CHAR)
		return (ft_is_str_label_param(arg + 1) ? T : F);
	else if (ft_isnumerique(arg))
		return (T);
	return (F);
}
