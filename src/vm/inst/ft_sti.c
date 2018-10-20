/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:50 by mint              #+#    #+#             */
/*   Updated: 2018/10/20 17:33:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**  a tester
** ************************************************************************* **
*/

static int	get_val_arg2(t_vm *vm, t_process *process, int param2)
{
	int ret;

	ret = param2;
	if (process->curent_instruction.type_arg[1][TYPE_2] == REG_CODE)
		ret = process->reg[param2 - 1];
	else if (process->curent_instruction.type_arg[1][TYPE_2] == IND_CODE)
		ret = ft_read_indirect(vm, param2 % IDX_MOD);
	else if (process->curent_instruction.type_arg[1][TYPE_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[1];
	return (ret);
}

static int	get_val_arg3(t_process *process, int param3)
{
	int ret;

	ret = param3;
//	ft_printf(" param 3 = [%d]\n", param3);
	if (process->curent_instruction.type_arg[2][TYPE_2] == REG_CODE)
		ret = process->reg[param3 - 1];
	else if (process->curent_instruction.type_arg[2][TYPE_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[2];
	return (ret);
}

BOOL		ft_sti(t_vm *vm, t_process *process)
{
	int id_reg;
	int param2;
	int param3;
	int add;
	int val;

	id_reg = process->curent_instruction.vale_arg[0] - 1;
	if (id_reg < 0 || id_reg > REG_NUMBER)
		return (F);
	val = process->reg[id_reg];
	param2 = get_val_arg2(vm, process, process->curent_instruction.vale_arg[1])
	% IDX_MOD;
	param3 = get_val_arg3(process, process->curent_instruction.vale_arg[2])
	% IDX_MOD;
	add = ((param2 + param3) % IDX_MOD) + process->curent_pc;
	ft_put_to_mem(add, val, process, vm);
	return (T);
}
