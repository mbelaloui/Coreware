/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:05 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 14:38:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_zjmp(t_vm *vm, t_process *process)
{
	int		val;

	val = process->curent_instruction.vale_arg[0];
	if (process->carry)
	{
		process->pc = ft_calcule_add(val, process->curent_pc);
		vm->mem[process->pc][MEM_DESC] -= NULL_COLOR;
		process->curent_pc = process->pc;
		vm->mem[process->pc][MEM_DESC] += NULL_COLOR;
	}
	(void)vm;
	return (T);
}
