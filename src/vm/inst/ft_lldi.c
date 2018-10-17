/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:34 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 20:54:27 by mbelalou         ###   ########.fr       */
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
	int				ret;

	ret = param1;
	if (process->curent_instruction.type_arg[0] == REG_CODE)
		ret = process->reg[param1 - 1];
	else if (process->curent_instruction.type_arg[0] == IND_CODE)
		ret = ft_read_indirect(vm, param1 % IDX_MOD);
	else if (process->curent_instruction.type_arg[0] == DIR_CODE)
		ret = param1;
	return (ret);
}

static int	get_val_arg2(t_process *process, int param2)
{
	int ret;

	ret = param2;
	if (process->curent_instruction.type_arg[1] == REG_CODE)
		ret = process->reg[param2 - 1];
	else if (process->curent_instruction.type_arg[1] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[1];
	return (ret);
}

BOOL	ft_lldi(t_vm *vm, t_process *process)
{
	int param1;
	int param2;
	int id_reg_dest;
	int add;

	param1 = get_val_arg1(vm, process, process->curent_instruction.vale_arg[0]);
	param2 = get_val_arg2(process, process->curent_instruction.vale_arg[1]);
	id_reg_dest = process->curent_instruction.vale_arg[2] - 1;
	add = process->curent_pc + param1 + param2;
	process->reg[id_reg_dest] = ft_read_indirect(vm, add);
	//process->carry = (process->reg[id_reg_dest]) ? F : T;
	return (T);
}
