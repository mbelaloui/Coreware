/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_label_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:52:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/05 15:18:06 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_str_label_param(char *str)
{
	int i;

	//if (ft_is_name_op(str) == -1)
	{
		i = 0;
		while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
			i++;
		return (str[i]) ? F : T;
	}
//	else   un nom de fonction ne peut etre utilier en tanque label
//	ft_error_label(ERROR_LABEL_EXPECTED_BUT_OPR_FOUNF, '', str);

	return (F);
}
