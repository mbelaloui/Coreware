/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:51:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:18:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static int	get_size_arg(char *arg, t_op *op_tab[NBR_OP], char *name)
{
	t_op *op;

	op = ft_get_op(op_tab, name);
	if (ft_is_direct(arg))
		return (op->size_label);
	if (ft_is_indirect(arg))
		return (IND_SIZE);
	if (ft_is_register(arg))
		return (REG_SIZE);
	return (-1);
}

static int	get_size_inst(t_inst *inst)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (i < SIZE_INST)
	{
		if (inst->size[i] != -1)
			size += inst->size[i];
		i++;
	}
	return (size);
}

void		ft_get_size_inst(t_inst *inst, t_op *op_tab[NBR_OP])
{
	t_charlist	*pt;
	int			i;

	inst->size[LABL] = (inst->label) ? 0 : -1;
	if (inst->opcode)
	{
		inst->size[OPPR] = 1;
		inst->size[DESC] = (ft_is_need_desc_op(inst->opcode, op_tab))
			? 1 : -1;
		i = 3;
		pt = inst->param;
		while (pt)
		{
			inst->size[i++] = get_size_arg(pt->data, op_tab,
					inst->opcode);
			pt = pt->next;
		}
	}
	else
		inst->size[OPPR] = -1;
	inst->size_inst = get_size_inst(inst);
}
