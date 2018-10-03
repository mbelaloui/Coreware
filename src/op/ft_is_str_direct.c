/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_direct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:36:52 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/30 21:08:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_str_direct(char *arg)
{
	if (arg[0] == DIRECT_CHAR)
		return (ft_is_str_indirect(arg + 1));
	return (F);
}
