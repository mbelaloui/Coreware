/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:05 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 14:58:56 by mint             ###   ########.fr       */
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

	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
	ft_free_optab(op_tab);

	ft_printf("  pc =%d  ", process->pc);

	if (process->carry)
		process->pc = process->curent_instruction.vale_arg[0] - 1; // voir si c'est pas <pc += val>
	ft_printf("  pc =%d  ", process->pc);

	return (T);
}