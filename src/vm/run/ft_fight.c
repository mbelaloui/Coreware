/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:30:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 17:48:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

static BOOL	execution(t_vm *vm, t_process *process)
{
	if (process->curent_instruction.id_opr > 0
		&& process->curent_instruction.id_opr <= NBR_OP)
		process->a_live =
			vm->action_instructions[process->curent_instruction.id_opr]
(vm, process);
	return (T);
}

static void	run_cycle(t_vm *vm, t_process *list_process, t_op *op_tab[NBR_OP])
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
	if (vm->op_vm->v)
		ft_put_mem(vm->mem);
	else if (vm->op_vm->g)
		ft_print_visu(vm);
}

static void	new_cycle(t_vm *vm)
{
	vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
	vm->check = 1;
}

void		ft_fight(t_vm *vm)
{
	int nbr_live_cycl;

	while (vm->cycle_to_die > 1)
	{
		ft_bzero(vm->live, MAX_PLAYERS * 4);
		vm->time = 0;
		vm->total_live_cycle = 0;
		while (vm->time < vm->cycle_to_die)
		{
			run_cycle(vm, vm->head_list_process, vm->op_tab);
			if ((vm->time_total + (vm->time++)) == vm->dump)
				ft_dump(vm);
		}
		vm->time_total += vm->time;
		if ((nbr_live_cycl = ft_check_survivor(vm->head_list_process, vm)) <= 0)
			ft_put_winer(vm);
		else if (nbr_live_cycl >= NBR_LIVE)
			new_cycle(vm);
		else if (vm->check == MAX_CHECKS)
			new_cycle(vm);
		else
			vm->check++;
	}
}
