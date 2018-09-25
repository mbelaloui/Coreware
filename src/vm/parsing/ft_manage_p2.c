/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:23:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 18:24:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static BOOL	is_good_arg2_type(int arg, int desc)
{
	if (arg == REG_CODE)
		if (desc & T_REG_P2)
			return (T);
	if (arg == DIR_CODE)
		if (desc & T_DIR_P2)
			return (T);
	if (arg == IND_CODE)
		if (desc & T_IND_P2)
			return (T);
	return (F);
}

int	ft_manage_p2(int desc, t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	arg;
	unsigned char	arg_temp;
	int				size;

	size = 0;
	arg_temp = (desc << 2);
	arg = arg_temp >> 6;
	if (is_good_arg2_type(arg, op->param))
		size = ft_get_size_param(op_tab, op->mnemonique,  arg);
	else
	{
		ft_printf("22222222 :wvoila error bad decription param in argument\n");////////////
		exit(-555555555);
	}
	return (size);
}
