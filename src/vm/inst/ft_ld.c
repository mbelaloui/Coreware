/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 19:48:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** fonction a tester fini
** ************************************************************************* **
*/

static int	get_val_arg1(t_vm *vm, t_process *process, int param1)
{
	int ret;

	ret = param1;
	if (process->curent_instruction.type_arg[0][TYPE_2] == IND_CODE)
	{
		param1 = process->curent_pc + (param1 % IDX_MOD);
		ret = ft_read_indirect(vm, param1);
	}
	else if (process->curent_instruction.type_arg[0][TYPE_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[0];
	return (ret);
}

int			ft_ld(t_vm *vm, t_process *process)
{
	int				val;
	int				id_reg;

	val = get_val_arg1(vm, process, process->curent_instruction.vale_arg[0]);
	id_reg = process->curent_instruction.vale_arg[1] - 1;
	if (!ft_is_good_id_reg(id_reg))
		return (F);
	process->reg[id_reg] = val;
	process->carry = (process->reg[id_reg]) ? F : T;
	return (T);
}
