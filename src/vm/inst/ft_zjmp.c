/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:05 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 08:34:10 by mint             ###   ########.fr       */
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
	ft_printf("  pc =%d  ", process->pc);
	if (process->carry)
	{
		if (process->curent_instruction.vale_arg[0] > 0)
			process->pc = process->curent_pc + process->curent_instruction.vale_arg[0] % MEM_SIZE;
	}
	ft_printf("  pc =%d  ", process->pc);

	(void)vm;
	return (T);
}