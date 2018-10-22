/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:10:42 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 19:11:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static BOOL	execution(t_vm *vm, t_process *process)
{
	if (process->curent_instruction.id_opr > 0
		&& process->curent_instruction.id_opr <= NBR_OP)
		process->a_live =
			vm->action_instructions[process->curent_instruction.id_opr]
(vm, process);
	return (T);
}

static void	print(t_vm *vm)
{
	if (vm->op_vm->v)
		ft_put_mem(vm->mem);
	else if (vm->op_vm->g)
		ft_print_visu(vm);
}

void		run_cycle(t_vm *vm, t_process *list_process, t_op *op_tab[NBR_OP])
{
	t_process *process;

	process = list_process;
	if (!process)
		ft_put_winer(vm);
	while (process)
	{
		if (process->time_to_exe > 1)
			process->time_to_exe--;
		else
		{
			if (process->curent_instruction.id_opr != -1)
			{
				ft_rest_color(vm, process);
				execution(vm, process);
			}
			ft_bzero((&process->curent_instruction),
			sizeof(process->curent_instruction));
			ft_get_next_instuction(&process->curent_instruction, vm,
				process, op_tab);
		}
		process = process->next;
	}
	print(vm);
}
