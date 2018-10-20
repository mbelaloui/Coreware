/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:36:11 by mint              #+#    #+#             */
/*   Updated: 2018/10/20 16:06:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/


/*
	ft_printf("val desc = [%d]\n",
		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC]
		);

	ft_printf("proceess id = [%d], val desc = [%d]    id + null = [%d]\n",
	process->id_parent,
		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC],
	process->id_parent + NULL_COLOR
		);

*/

void	ft_rest_color(t_vm *vm, t_process *process)
{
	if (process->curent_instruction.id_opr == 0)
	{
		if (vm->mem[process->curent_pc][MEM_DESC] == REVERS_COLOR)
			vm->mem[process->curent_pc][MEM_DESC] -= NULL_COLOR;
	}
	else if (process->curent_instruction.id_opr > 0)
	{
	//	if (REVERS_COLOR <= vm->mem[((process->curent_pc)
	//	% MEM_SIZE)][MEM_DESC] && process->curent_instruction.id_opr == 0)
	//	{
	//		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC]
	//		-= NULL_COLOR;
/*	ft_printf("proceess id = [%d], val desc = [%d]    id + null = [%d]\n",
	process->id_parent,
	vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC],
	process->id_parent + NULL_COLOR
		);


		exit(0);
*/

	//	}
///		if (process->id_parent + REVERS_COLOR == vm->mem[((process->curent_pc)
//		% MEM_SIZE)][MEM_DESC])
//		{
		if (vm->mem[process->curent_pc][MEM_DESC] > REVERS_COLOR)
			vm->mem[process->curent_pc][MEM_DESC]
				-= NULL_COLOR;

/*
	ft_printf("proceess id = [%d], val desc = [%d]    id + null = [%d]\n",
	process->id_parent,
		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC],
	process->id_parent + NULL_COLOR
		);
*/
//	exit(0);
//
//		}
	}
}
