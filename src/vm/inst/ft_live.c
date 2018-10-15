/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:48 by mint              #+#    #+#             */
/*   Updated: 2018/10/15 11:13:31 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**	
** ************************************************************************* **
*/

BOOL	ft_live(t_vm *vm, t_process *process)
{
	int live_for;
	t_champ *pt_champ;

	process->nbr_live++;
	live_for = process->curent_instruction.vale_arg[0];
	pt_champ = vm->champs;
	while (pt_champ)
	{
		if (pt_champ->id == live_for) // ajouter des messages d'erreures/reusit
			vm->id_last_a_live = live_for;
		pt_champ = pt_champ->next;
	}

//	ft_printf(" love fore %d,  id %d \n", live_for, vm->champs->id);

//	exit(0);
	return (T);
}