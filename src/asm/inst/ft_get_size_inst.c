/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_inst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:51:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 13:33:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int	get_size_arg(char *arg, t_op *op_tab[NBR_OP], char *name)
{
	t_op *op;

	op = ft_get_op(op_tab, name);
	if (ft_is_str_register(arg))
		return (REG_SIZE);
	else if (ft_is_str_indirect(arg))
		return (IND_SIZE);
	else if (ft_is_str_direct(arg))
		return (op->size_label);
	return (-1);
}

/*
**	in put
**	{
**		inst	<a structure which contain the instruction
**					[line of the source code]>
**		op_tab	<the table that contains the information
**					 about the instructions>
**	}
**
**	what the fonction do ??
**	this function look for the size of the instruction process the
**		instruction with OCP and without
**	{
**		1 - {label}			size	0/oct
**		2 - {instruction}	size 	1/oct
**		3 - {[argument]}	size	1-2-4/oct
**			the register	size	1/oct
**			the indirect	size	2/oct
**			the direct		size	2-4/oct	different from a funtion to
**										another see "op->size_label"
**	}
**
**	output
**	{
**		add the size of each part of intruction
**				 in a static table {not malloced table}
**		tab[0/LABL] is for if there's a label			size = 0 else -1
**		tab[1/OPPR] is for the operation				size = 1 else -1
**		tab[2/DESC] is for if the operation had a OCP	size = 1 else -1
**		tab[3/ARG1] is for the size fist argument of the operation
**		tab[4/ARG2] is for the size second argument of the operation
**		tab[5/ARG3] is for the size third argument of the operation
**		NB <-1> if a element is not defined and will be ignored when
**				calculating the size of th instruction
**	}
*/

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
	inst->size_inst = ft_get_size_bin_inst(inst->size);
}
