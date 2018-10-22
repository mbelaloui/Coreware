/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:48 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 19:33:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** a tester
** ************************************************************************* **
*/

int	ft_live(t_vm *vm, t_process *process)
{
	t_champ	*pt_champ;
	int		live_for;
	int		pt_tab;

	process->nbr_live++;
	vm->total_live_cycle++;
	live_for = process->curent_instruction.vale_arg[0];
	pt_champ = vm->champs;
	while (pt_champ)
	{
		if (pt_champ->num == live_for)
		{
			pt_tab = pt_champ->pos - 1;
			if (vm->op_vm->v)
				ft_printf("un processus dit que le joueur %d({green}%s{eoc})"
				" est en vie", pt_champ->pos, pt_champ->name);
			vm->id_last_a_live = live_for;
			vm->live[pt_tab] = vm->live[pt_tab] + 1;
			vm->time_last_live[pt_tab] = vm->time_total + vm->time;
			return (T);
		}
		pt_champ = pt_champ->next;
	}
	return (F);
}
