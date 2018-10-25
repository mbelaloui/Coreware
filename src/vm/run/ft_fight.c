/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:30:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/25 08:43:06 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	new_cycle(t_vm *vm)
{
	vm->cycle_to_die = vm->cycle_to_die - CYCLE_DELTA;
	vm->check = 1;
}

static void	init_live(t_vm *vm)
{
	int pt;

	pt = 0;
	while (pt < MAX_PLAYERS)
	{
		vm->live[pt] = 0;
		pt++;
	}
}

void		ft_fight(t_vm *vm)
{
	int nbr_live_cycl;

	while (vm->cycle_to_die > 1)
	{
		init_live(vm);
		vm->time = 0;
		vm->total_live_cycle = 0;
		while (vm->time < vm->cycle_to_die)
		{
			run_cycle(vm, vm->head_list_process, vm->op_tab);
			if ((vm->time_total + (vm->time++)) == vm->dump)
				ft_dump(vm);
		}
		vm->time_total += vm->time;
		if ((nbr_live_cycl = ft_check_survivor(vm->head_list_process, vm)) < 1)
			ft_put_winer(vm);
		if (nbr_live_cycl >= NBR_LIVE)
			new_cycle(vm);
		else if (vm->check == MAX_CHECKS)
			new_cycle(vm);
		else
			vm->check++;
	}
}
