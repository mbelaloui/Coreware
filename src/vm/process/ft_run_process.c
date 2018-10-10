/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:28:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 19:49:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	rest_color(t_vm *vm, int start, t_process *process)
{
	while (start < process->pc)
	{
		vm->mem[start][MEM_DESC] = process->id_parent;
		start++;
	}
}

void	ft_run_process(t_opr_exe *opr_exe, t_vm *vm, t_process *process, t_op *op_tab[NBR_OP])
{
	int			color_start;

	opr_exe->id_opr = vm->mem[process->pc][MEM_SRC];
	
	if (opr_exe->id_opr > 0 && opr_exe->id_opr < 17)
	{
/*		ft_printf("Process reated by [%d] is in [%d]  cas [%.2x]",
		process->id_parent, process->pc, opr_exe.id_opr);
*/
//		vm->mem[process->pc][MEM_DESC] = process->id_parent;
//		ft_put_mem(vm->mem);

		if (op_tab[opr_exe->id_opr]->desc_param)
			color_start = ft_process_desc_ok(opr_exe, op_tab, vm, process);
		else
			color_start = ft_process_desc_ko(opr_exe, op_tab, vm, process);
		rest_color(vm, color_start, process);
//		process->pc++;
	//enlever la couleur ici
	}
	else if (opr_exe->id_opr == 0)
	{
		if (!vm->mem[((process->pc - 1) % MEM_SIZE)][MEM_SRC])
			vm->mem[((process->pc - 1) % MEM_SIZE)][MEM_DESC] = 0;
		if (!vm->mem[((process->pc + 1) % MEM_SIZE)][MEM_SRC])
			vm->mem[process->pc][MEM_DESC] = PT_COLOR;
		process->pc = (process->pc + 1) % MEM_SIZE;
	}
	else
	{
		ft_printf("Process reated by [%d] is in [%d]  cas [%.2x]",
		process->id_parent, process->pc, opr_exe->id_opr);

		ft_printf("error bad operations  []\n");
		exit(-4465);
	}
//	ft_printf("\n");
//	vm->mem[process->pc][MEM_DESC] = PT_COLOR;
//	ft_put_mem(vm->mem);
//	ft_printf("\n");
	//exit(0);
}
