/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:50 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 14:03:59 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_sti(t_vm *vm, t_process *process)
{
	int val_reg;
	int val_add;

	val_reg = process->curent_instruction.vale_arg[0];
	val_add = process->curent_instruction.vale_arg[1] +process->curent_instruction.vale_arg[2] % MEM_SIZE;

	vm->mem[val_add][MEM_SRC] = val_reg;	
	if (val_add)
		process->carry = 0;
	else
		process->carry = 1;

//	ft_get_op_tab(op_tab);
//	ft_put_opr_exe(&(process->curent_instruction), op_tab);
//	(void) vm;
//	ft_free_optab(op_tab);
	return (T);
}