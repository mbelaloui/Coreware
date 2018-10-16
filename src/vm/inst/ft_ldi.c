/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:53 by mint              #+#    #+#             */
/*   Updated: 2018/10/16 17:44:51 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_ldi(t_vm *vm, t_process *process)
{
	int val_arg_1;

	if (process->curent_instruction.type_arg[0] == REG_CODE)
		val_arg_1 = process->reg[process->curent_instruction.vale_arg[0] - 1];
	else
		val_arg_1 = process->curent_instruction.vale_arg[0];
	int val_arg_2 = process->curent_instruction.vale_arg[1];
	int id_reg = process->curent_instruction.vale_arg[2] - 1;
	int pt;
	unsigned char	tab[DIR_SIZE];
	int				max_read;
	
	pt = (((process->curent_pc + (val_arg_1 % IDX_MOD))) + val_arg_2) % IDX_MOD;


	ft_printf(" pt = %d arg 1 = %d   arg 2 = %d  \n",pt, val_arg_1, val_arg_2);
/*	exit(0);
*/
	if (((val_arg_1 % IDX_MOD) + val_arg_2) >= REG_NUMBER)
	{
		process->reg[id_reg] = 0;	
	}
	else
	{
	if (val_arg_1 % IDX_MOD)
		pt = (pt - 1) % IDX_MOD;
	pt = (pt - 1) % IDX_MOD;
	max_read = (pt + DIR_SIZE);
	while (pt < max_read)
	{
		tab[DIR_SIZE - (max_read - pt)] = vm->mem[pt][MEM_SRC];
		vm->mem[pt][MEM_DESC] = process->id_parent;
		pt = (pt + 1);
	}
	process->reg[id_reg] = ft_byts_to_int(tab);
	}
	if (process->reg[id_reg])
		process->carry = 0;
	else
		process->carry = 1;
	return (T);
}