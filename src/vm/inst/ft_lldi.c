/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:34 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 13:59:58 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_lldi(t_vm *vm, t_process *process)
{
	int arg1 = process->curent_instruction.type_arg[0];
	int arg2 = process->curent_instruction.type_arg[1];
	int result = arg1 + arg2;

	process->reg[process->curent_instruction.vale_arg[2]] = result;

	if (result)
		process->carry = 0;
	else
		process->carry = 1;

//	t_op	*op_tab[NBR_OP];

//	ft_get_op_tab(op_tab);
//	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
//	ft_free_optab(op_tab);
	return (T);
}