/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_asm_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:54:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:57:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

BOOL	ft_extract_asm_options(char *param, t_option *op, char *name)
{
	int index;

	index = 0;
	while (param[index])
	{
		if (param[index] == '-')
		{
			index++;
			if (ft_is_option(param[index]) && (param[index + 1] == ' '
						|| !ft_isalpha(param[index + 1])))
				ft_set_asm_options(param[index++], op);
			else
				ft_error_option(ERROR_UNKNOWN_ARG, name,
						op, param[index]);
		}
		else if (ft_isblank(param[index]))
			index++;
		else
			break ;
	}
	return (index);
}
