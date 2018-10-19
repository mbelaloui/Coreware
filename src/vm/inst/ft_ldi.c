/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:53 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 11:32:40 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** a tester
** ************************************************************************* **
*/

static int	get_val_arg1(t_vm *vm, t_process *process, int param1)
{
	int ret;

	ret = param1;
	if (process->curent_instruction.type_arg[0][type_2] == REG_CODE)
		ret = process->reg[param1 - 1];
	else if (process->curent_instruction.type_arg[0][type_2] == IND_CODE)
		ret = ft_read_indirect(vm, param1 % IDX_MOD);
	else if (process->curent_instruction.type_arg[0][type_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[0];
	return (ret);
}

static int	get_val_arg2(t_process *process, int param2)
{
	int ret;

	ret = param2;
	if (process->curent_instruction.type_arg[1][type_2] == REG_CODE)
		ret = process->reg[param2 - 1];
	else if (process->curent_instruction.type_arg[1][type_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[1];
	return (ret);
}

BOOL		ft_ldi(t_vm *vm, t_process *process)
{
	int param1;
	int param2;
	int id_reg_dest;
	int add;

	param1 = get_val_arg1(vm, process,
	process->curent_instruction.vale_arg[0]) % IDX_MOD;
	param2 = get_val_arg2(process,
	process->curent_instruction.vale_arg[1]) % IDX_MOD;
	id_reg_dest = process->curent_instruction.vale_arg[2] - 1;
	add = (process->curent_pc + (param1 + param2) % IDX_MOD) % MEM_SIZE;
	process->reg[id_reg_dest] = ft_read_indirect(vm, add);
	return (T);
}
