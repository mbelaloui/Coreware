/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_instuction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:28:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/25 08:45:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_get_next_instuction(t_opr_exe *opr_exe, t_vm *vm,
		t_process *process, t_op *op_tab[NBR_OP])
{
	process->curent_pc = process->pc % MEM_SIZE;
	opr_exe->id_opr = vm->mem[process->pc % MEM_SIZE][MEM_SRC];
	if (opr_exe->id_opr > 0 && opr_exe->id_opr < 17)
	{
		if (vm->mem[process->pc % MEM_SIZE][MEM_DESC] < REVERS_COLOR)
			vm->mem[process->pc % MEM_SIZE][MEM_DESC] += NULL_COLOR;
		if (op_tab[opr_exe->id_opr]->desc_param)
			ft_process_desc_ok(opr_exe, op_tab, vm, process);
		else
			ft_process_desc_ko(opr_exe, op_tab, vm, process);
	}
	else
	{
		opr_exe->id_opr = 0;
		if (vm->mem[process->pc % MEM_SIZE][MEM_DESC] == NULL_COLOR)
			vm->mem[process->pc % MEM_SIZE][MEM_DESC] += NULL_COLOR;
		process->pc = (process->pc + 1) % MEM_SIZE;
	}
	process->time_to_exe = op_tab[process->curent_instruction.id_opr]->cycle;
}
