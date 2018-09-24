/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_op_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:14:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 11:21:06 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_put_op_param_3(t_op *op)
{
	if (op->param & T_REG_P3)
		ft_printf("{RED}registre{eoc}");
	if (op->param & T_IND_P3)
	{
		if (op->param & T_REG_P3)
			ft_printf(" ");
		ft_printf("{YELLOW}indirect{eoc}");
	}
	if (op->param & T_DIR_P3)
	{
		if (op->param & T_REG_P3 || op->param & T_IND_P3)
			ft_printf(" ");
		ft_printf("{GREEN}direct{eoc}");
	}
}

void	ft_put_op_param_2(t_op *op)
{
	if (op->param & T_REG_P2)
		ft_printf("{RED}registre{eoc}");
	if (op->param & T_IND_P2)
	{
		if (op->param & T_REG_P2)
			ft_printf(" ");
		ft_printf("{YELLOW}indirect{eoc}");
	}
	if (op->param & T_DIR_P2)
	{
		if (op->param & T_REG_P2 || op->param & T_IND_P2)
			ft_printf(" ");
		ft_printf("{GREEN}direct{eoc}");
	}
}

void	ft_put_op_param_1(t_op *op)
{
	if (op->param & T_REG_P1)
		ft_printf("{RED}registre{eoc}");
	if (op->param & T_IND_P1)
	{
		if (op->param & T_REG_P1)
			ft_printf(" ");
		ft_printf("{YELLOW}indirect{eoc}");
	}
	if (op->param & T_DIR_P1)
	{
		if (op->param & T_REG_P1 || op->param & T_IND_P1)
			ft_printf(" ");
ft_printf("{GREEN}direct{eoc}");
	}
}
