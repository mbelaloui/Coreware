/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_instuction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:28:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/11 16:51:46 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_get_next_instuction(t_opr_exe *opr_exe, t_vm *vm, t_process *process,
	t_op *op_tab[NBR_OP])
{
	opr_exe->id_opr = vm->mem[process->pc][MEM_SRC];
	if (opr_exe->id_opr > 0 && opr_exe->id_opr < 17)
	{
		if (op_tab[opr_exe->id_opr]->desc_param)
			process->color_start = ft_process_desc_ok(opr_exe, op_tab,
				vm, process);
		else
			process->color_start = ft_process_desc_ko(opr_exe, op_tab,
				vm, process);
	}
	else if (opr_exe->id_opr == 0)
	{
		vm->mem[process->pc][MEM_DESC] = PT_COLOR;
		process->color_start = process->pc;
		process->pc = (process->pc + 1) % MEM_SIZE;
	}
	else
	{
/*
	else
	{
		kill the process :
		set the process as kiled
	or
		free the process
	}
*/
		ft_printf("Process reated by [%d] is in [%d]  cas [%.2x]",
		process->id_parent, process->pc, opr_exe->id_opr);
		ft_printf("error bad operations  []\n");
		exit(-4465);// ou juste tuer le process a voir le sujet
	}
}
