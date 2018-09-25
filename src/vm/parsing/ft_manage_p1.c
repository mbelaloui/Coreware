/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:25:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 18:26:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static BOOL	is_good_arg1_type(int arg, int desc)
{
	if (arg == REG_CODE)
		if (desc & T_REG_P1)
			return (T);
	if (arg == DIR_CODE)
		if (desc & T_DIR_P1)
			return (T);
	if (arg == IND_CODE)
		if (desc & T_IND_P1)
			return (T);
	return (F);
}

int	ft_manage_p1(int desc, t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	arg;
	int				size;

	size = 0;
	arg = desc >> 6;

	if (is_good_arg1_type(arg, op->param))
		size = ft_get_size_param(op_tab, op->mnemonique,  arg);
	else
	{
		ft_printf("voila error bad decription param in argument\n"); ///////////////
		exit(-555555555);
	}
	return (size);
}
