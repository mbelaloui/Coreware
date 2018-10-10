/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:30:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 11:12:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void run_cycle(t_vm *vm, t_process *list_process, t_op *op_tab[NBR_OP])
{
	while (list_process)
	{
		ft_run_process(vm, list_process, op_tab);
		list_process = list_process->next;
	}
}

/*
** 		time = 0;//cycle_to_die;
*/

void		ft_fight(t_vm *vm, t_process *list_process)
{
	int time_total;
	int cycle_to_die;
	int time;
	int check;
	t_op			*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	check = 1;
	cycle_to_die = CYCLE_TO_DIE;
	time_total = 0;
	while (cycle_to_die > 0)
	{
		time = 0;
		while (time < cycle_to_die)
		{
			if (time_total == vm->dump)
				break;//ft_dump(vm);
			run_cycle(vm, list_process, op_tab);
		//	return ;
/*
			if ((time % 10)== 0)
				ft_printf("\n");
			ft_printf("time = {green}[%d]{eoc}\t", time);
*/			
	//ft_temporize(3);
//	ft_clear_scr();
			time ++;
			time_total++;
			//ft_visu(vm, list_process);
//			ft_put_mem(vm->mem);
			//print mem   // visu

//			ft_printf("{blue}--------------------------------------{eoc}\n");

		}
	//	if (!ft_check_survivor(list_process))
	//		ft_printf("put wine ... plus de process vivant\n");
	//	if (ft_get_total_live(list_process) >= NBR_LIVE)
	//		cycle_to_die =- CYCLE_DELTA;
		if (check == MAX_CHECKS)
		{
			cycle_to_die -= CYCLE_DELTA;
			check = 1;
		}
		else
			check++;
	}
	(void) list_process;
	ft_free_optab(op_tab);
	ft_printf("\n\n {red}time total = %d{eoc} \n\n",  time_total);
}
