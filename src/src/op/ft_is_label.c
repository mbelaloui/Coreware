/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:36:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 13:55:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_label(char *str)
{
	int i;

	if (ft_is_name_op(str) == -1)
	{
		i = 0;
		while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
			i++;
		return (str[i]) ? F : T;
	}
	return (F);
}
