/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_desc_ok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:25:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:56:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static int		get_nbr_param(int desc)
{
	int cp;

	cp = 0;
	while (desc & MASK_PARAM)
	{
		cp++;
		desc = desc << 2;
	}
	return (cp);
}

static BOOL	is_valide_desc_arg(t_vm *vm, t_opr_exe *opr)
{
	int pt;

	pt = 0;
	while (pt < opr->nbr_param)
	{
		if (!(vm->op_tab[opr->id_opr]->param & opr->type_arg[pt][TYPE_1]))
		{
			opr->id_opr = 0;
			return (F);
		}
		pt++;
	}
	return (T);
}

int		ft_process_desc_ok(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
	int temp_pc;
	int start;

	start = process->pc;
	temp_pc = (process->pc + 1) % MEM_SIZE;
	opr_exe->nbr_param = get_nbr_param(vm->mem[temp_pc][MEM_SRC]);
	ft_set_desc_arg(vm->mem[temp_pc][MEM_SRC], opr_exe->nbr_param,
		opr_exe);
	if (!is_valide_desc_arg(vm, opr_exe))
		return (start);
	temp_pc = (temp_pc + 1) % MEM_SIZE;
	ft_set_size_arg(opr_exe, op_tab);
	process->pc = ft_set_vale_arg(vm, temp_pc, opr_exe);
	return (0);
}
