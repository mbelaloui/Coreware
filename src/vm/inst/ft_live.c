/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:48 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 23:17:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** a tester
** ************************************************************************* **
*/

BOOL	ft_live(t_vm *vm, t_process *process)
{
	t_champ	*pt_champ;
	int		live_for;

	process->nbr_live++;
	vm->total_live_cycle++;
	live_for = process->curent_instruction.vale_arg[0];
	pt_champ = vm->champs;
	while (pt_champ)
	{
		if (pt_champ->num == live_for)
		{
			vm->id_last_a_live = live_for;
//			ft_printf("pos = [%d]\n", pt_champ->pos);
//			exit(0);
			vm->live[pt_champ->pos]++;
			return (T);
		}
		pt_champ = pt_champ->next;
	}
	return (T);
	(void)vm;
//	return (F);
}
