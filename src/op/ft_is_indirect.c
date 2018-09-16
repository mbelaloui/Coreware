/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_indirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:37:21 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 13:55:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_indirect(char *arg)
{
	if (arg[0] == LABEL_CHAR)
		return (ft_is_label(arg + 1) ? T : F);
	else if (ft_isnumerique(arg))
		return (T);
	return (F);
}
