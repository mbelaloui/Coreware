/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_label_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:52:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:59:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_str_label_param(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
		i++;
	return (str[i]) ? F : T;
}
