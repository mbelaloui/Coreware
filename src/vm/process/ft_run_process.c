/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:28:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 11:06:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_run_process(t_vm *vm, t_process *process, t_op *op_tab[NBR_OP])
{
	t_opr_exe	opr_exe;

	ft_bzero(&opr_exe, sizeof(t_opr_exe));
	opr_exe.id_opr = vm->mem[process->pc][MEM_SRC];
	if (opr_exe.id_opr > 0 && opr_exe.id_opr < 17)
	{
		ft_printf("Process reated by [%d] is in [%d]  cas [%.2x]",
		process->id_parent, process->pc, opr_exe.id_opr);
		process->pc = (process->pc + 1) % MEM_SIZE;
		if (op_tab[opr_exe.id_opr]->desc_param)
			ft_process_desc_ok(&opr_exe, op_tab, vm, process);
		else
			ft_process_desc_ko(&opr_exe, op_tab, vm, process);
	}
	else if (opr_exe.id_opr == 0)
		process->pc = (process->pc + 1) % MEM_SIZE;
	else
	{
		ft_printf("error bad operations\n");
		exit(-4465);
	}
	ft_printf("\n");
}
