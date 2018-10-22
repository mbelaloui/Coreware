/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:34 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 19:43:39 by mbelalou         ###   ########.fr       */
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
	if (process->curent_instruction.type_arg[0][TYPE_2] == REG_CODE)
		ret = process->reg[param1 - 1];
	else if (process->curent_instruction.type_arg[0][TYPE_2] == IND_CODE)
	{
		param1 = process->curent_pc + (param1 % IDX_MOD);
		ret = ft_read_indirect(vm, param1);
	}
	else if (process->curent_instruction.type_arg[0][TYPE_2] == DIR_CODE)
		ret = param1;
	return (ret);
}

static int	get_val_arg2(t_process *process, int param2)
{
	int ret;

	ret = param2;
	if (process->curent_instruction.type_arg[1][TYPE_2] == REG_CODE)
		ret = process->reg[param2 - 1];
	else if (process->curent_instruction.type_arg[1][TYPE_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[1];
	return (ret);
}

int			ft_lldi(t_vm *vm, t_process *process)
{
	int param1;
	int param2;
	int id_reg_dest;
	int add;

	if (process->curent_instruction.type_arg[0][TYPE_2] == REG_CODE
	&& !ft_is_good_id_reg(process->curent_instruction.vale_arg[0] - 1))
		return (F);
	param1 = get_val_arg1(vm, process, process->curent_instruction.vale_arg[0]);
	if (process->curent_instruction.type_arg[1][TYPE_2] == REG_CODE
	&& !ft_is_good_id_reg(process->curent_instruction.vale_arg[1] - 1))
		return (F);
	param2 = get_val_arg2(process, process->curent_instruction.vale_arg[1]);
	id_reg_dest = process->curent_instruction.vale_arg[2] - 1;
	if (!ft_is_good_id_reg(id_reg_dest))
		return (F);
	add = (process->curent_pc + param1 + param2);
	process->reg[id_reg_dest] = ft_read_indirect(vm, add);
	process->carry = (process->reg[id_reg_dest]) ? F : T;
	return (T);
}
