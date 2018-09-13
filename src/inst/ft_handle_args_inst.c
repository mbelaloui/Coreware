/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_args_inst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:00:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:01:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_handle_args_inst(char **tab_args, char *name_op, char *args, t_op *op)
{
	int pos;
	int param;

	pos = 0;
	while (tab_args[pos])
	{
		if (!(param = ft_get_type_args(tab_args[pos], pos)))
			ft_error_args(ERROR_TYPE_ARG,
					name_op, args, tab_args[pos]);
		if (!(param & op->param))
			ft_error_args(ERROR_TYPE_ARG,
					name_op, args, tab_args[pos]);
		pos++;
	}
}
