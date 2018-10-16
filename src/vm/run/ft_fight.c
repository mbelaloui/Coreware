/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:30:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/16 10:25:27 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	put_winer(t_champ *winer)
{
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/ %-42s \\\n", winer->name);
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
		if (pt_champ->id == vm->id_last_a_live)
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
			ft_init_tab_instruction(action_instructions);//mettre en dehors de cette fonction un peut plus en avant
			action_instructions[process->curent_instruction.id_opr](vm, process);
		}
/*
		else
		{
			kill the process :
			set the process as kiled
		or
			free the process
		}
*/
	}
	return (T);
}

static void run_cycle(t_vm *vm, t_process *list_process, t_op *op_tab[NBR_OP])
{
	BOOL	live;
	

	live = F;
	while (list_process)
	{
//		ft_printf("pc = %d         ", list_process->pc);
		if (list_process->a_live)
		{
			live = T;
			if (list_process->time_to_exe > 0)
				list_process->time_to_exe--;
			else
			{
				if(list_process->curent_instruction.id_opr != -1) 
				{
			//		ft_printf("{green}\n\n icicic \n\n {eoc}");
					ft_rest_color(vm, list_process);
					execution(vm, list_process);//can be used to kill the process if i get process id_opr == 0 ==> kill
				}
				ft_bzero((&list_process->curent_instruction),
				sizeof(list_process->curent_instruction));
				ft_get_next_instuction(&list_process->curent_instruction, vm,
					list_process, op_tab);
				list_process->time_to_exe = op_tab[list_process->curent_instruction.id_opr]->cycle;
			}
		}
		list_process = list_process->next;
	}
	if (!live)
		ft_put_winer(vm);
	
	ft_put_mem(vm->mem);
}

void		ft_fight(t_vm *vm, t_process *list_process)
{
	t_op	*op_tab[NBR_OP];
/*	int 	cycle_to_die;
	int		time_total;
	int 	check;
	int 	time;
*/
	ft_get_op_tab(op_tab);
	vm->cycle_to_die = CYCLE_TO_DIE;// mettre dans la structure vm 
	vm->time_total = 0;				// aussi 								cycle 
	vm->check = 1;
	while (vm->cycle_to_die > 0)
	{
		vm->time = 0;
		while (vm->time < vm->cycle_to_die)
		{

		if (vm->time_total + vm->time++ == vm->dump)
				ft_dump(vm);

//	ft_printf("\n\nn\n\n{green}dump = %d     time = %d{eoc}\n\n\n", vm->dump ,time_total + time  );

			run_cycle(vm, list_process, op_tab);

		}
		vm->time_total += vm->time;
		if (!ft_check_survivor(list_process, vm))
			ft_put_winer(vm);
		if (ft_get_total_live(list_process) >= NBR_LIVE)
			vm->cycle_to_die =- CYCLE_DELTA;
		if (vm->check == MAX_CHECKS)
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			vm->check = 1;
		}
		else
			vm->check++;
	}
	ft_free_optab(op_tab);
}
