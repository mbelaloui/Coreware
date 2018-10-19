/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:30:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 13:23:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	put_winer(t_champ *winer)
{
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/id champion [%d] %-25s \\\n", winer->num, winer->name);
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/ %-42s \\\n", winer->comment);
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
}

void	put_message(void)
{
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/ %-42s \\\n", "no champion has made live !!!!");
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
}

void	ft_put_winer(t_vm *vm)
{
	t_champ *pt_champ;
	t_champ *winer;

	winer = NULL;
	pt_champ = vm->champs;
	while (pt_champ)
	{
		if (pt_champ->num == vm->id_last_a_live)
			winer = pt_champ;
		pt_champ = pt_champ->next;
	}
	if (winer)
		put_winer(winer);
	else
		put_message();
	exit(0);
}

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL		execution(t_vm *vm, t_process *process)
{
	BOOL	(*action_instructions[NBR_OP])(t_vm *vm, t_process *process);

//	if (process->curent_instruction.id_opr != -1)
	{
		if (process->curent_instruction.id_opr > 0
		&& process->curent_instruction.id_opr <= NBR_OP)
		{
		//	ft_put_opr_exe(&(process->curent_instruction), vm->op_tab);
			ft_init_tab_instruction(action_instructions);//mettre en dehors de cette fonction un peut plus en avant
			action_instructions[process->curent_instruction.id_opr](vm, process);
//			ft_put_opr_exe(&(process->curent_instruction), vm->op_tab);


//			ft_put_mem(vm->mem);
//			exit(0);

		}
	}
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
		if (process->time_to_exe > 0)
			process->time_to_exe--;
		else
		{
			if (process->curent_instruction.id_opr != -1)
			{
			//	ft_put_opr_exe(&(process->curent_instruction), vm->op_tab);

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
//	exit(0);
	if (vm->op_vm->v)
		ft_put_mem(vm->mem);

}

void		ft_fight(t_vm *vm)
{
	int nbr_live_cycl;

	while (vm->cycle_to_die > 0)
	{
		vm->time = 0;
		while (vm->time < vm->cycle_to_die)
		{
			if (vm->time_total + vm->time++ == vm->dump)
				ft_dump(vm);
			run_cycle(vm, vm->head_list_process, vm->op_tab);
		}
		vm->time_total += vm->time;
		if ((nbr_live_cycl = ft_check_survivor(vm->head_list_process, vm)) < 0)
			ft_put_winer(vm);
		else if (nbr_live_cycl >= NBR_LIVE)
			vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->check == MAX_CHECKS)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			vm->check = 1;
		}
		else
			vm->check++;
	}
}
