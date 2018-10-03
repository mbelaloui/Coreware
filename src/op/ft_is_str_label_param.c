/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_label_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:52:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/30 20:01:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_str_label_param(char *str)
{
	int i;

	if (ft_is_name_op(str) == -1)
	{
		i = 0;
		while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
			return (str[i]) ? T : F;
		i++;
	}
	return (F);
}
