/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:50 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 14:19:20 by mbelalou         ###   ########.fr       */
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
	if (process->curent_instruction.type_arg[2][TYPE_2] == REG_CODE)
		ret = process->reg[param3 - 1];
	else if (process->curent_instruction.type_arg[2][TYPE_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[2];
	return (ret);
}

void		ft_put_to_mem(int add, int val, t_process *process, t_vm *vm)
{
	unsigned char	*tab;
	int				max_print;

	tab = ft_int_to_byts((unsigned)val, DIR_SIZE);
	max_print = add + DIR_SIZE;
	while (add < max_print)
	{
		vm->mem[add % MEM_SIZE][MEM_SRC] = tab[DIR_SIZE - (max_print - add)];
		vm->mem[add % MEM_SIZE][MEM_DESC] = process->id_parent + NULL_COLOR;
		add++;
	}
	free(tab);
}

BOOL		ft_sti(t_vm *vm, t_process *process)
{
	int id_reg;
	int param2;
	int param3;
	int add;
	int val;

	id_reg = process->curent_instruction.vale_arg[0] - 1;
	val = process->reg[id_reg];
	param2 = get_val_arg2(vm, process, process->curent_instruction.vale_arg[1])
	% IDX_MOD;
	param3 = get_val_arg3(process, process->curent_instruction.vale_arg[2])
	% IDX_MOD;
	add = (param2 % IDX_MOD) + (param3 % IDX_MOD) + process->curent_pc;
	ft_put_to_mem(add, val, process, vm);
	return (T);
}
