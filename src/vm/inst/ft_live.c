/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:48 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 21:15:42 by mbelalou         ###   ########.fr       */
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

	
	if (process->curent_instruction.type_arg[0] == DIR_CODE)
	{
		live_for = process->curent_instruction.vale_arg[0];
	

		pt_champ = vm->champs;
		while (pt_champ)
		{
	
	ft_printf("live for %d    is [%d]", live_for, pt_champ->id);
	
			if (pt_champ->id == live_for)
			{
				vm->id_last_a_live = live_for;
	
			}
			pt_champ = pt_champ->next;
		}
	///	exit(0);

		return (T);
	}
	
	return (F);
}
