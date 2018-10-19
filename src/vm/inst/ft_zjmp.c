/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:05 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 11:15:03 by mbelalou         ###   ########.fr       */
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
	val = (val > MEM_SIZE) ? (MEM_SIZE + val) - MEM_SIZE : val % IDX_MOD;
	if (process->carry)
	{
		if (process->curent_instruction.vale_arg[0] > 0)
			process->pc = (process->curent_pc + val) % MEM_SIZE;
	}
	(void)vm;
	return (T);
}
