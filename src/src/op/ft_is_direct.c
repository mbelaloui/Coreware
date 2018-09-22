/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_direct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:36:52 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 13:54:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_direct(char *arg)
{
	if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			return (ft_is_label(arg + 2) ? T : F);
		else
			return (ft_isnumerique(arg + 1) ? T : F);
	}
	return (F);
}
