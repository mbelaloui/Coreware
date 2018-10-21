/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:21:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:40:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static BOOL	is_good_arg3_type(int arg, int desc)
{
	if (arg == REG_CODE)
		if (desc & T_REG_P3)
			return (T);
	if (arg == DIR_CODE)
		if (desc & T_DIR_P3)
			return (T);
	if (arg == IND_CODE)
		if (desc & T_IND_P3)
			return (T);
	return (F);
}

int			ft_manage_p3(int desc, t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	arg;
	unsigned char	arg_temp;
	int				size;

	size = 0;
	arg_temp = (desc << 4);
	arg = arg_temp >> 6;
	if (is_good_arg3_type(arg, op->param))
		size = ft_get_size_param(op_tab, op->mnemonique, arg);
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);
	return (size);
}
