/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/20 18:29:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** fonction a tester fini
** ************************************************************************* **
*/

int			calcule_add(int val ,int pc)
{

	if (val < 32768)
	{
		ft_printf("{red} %d   a sub {eoc}",val - 32768);
		val = pc + ((val - 32768) % IDX_MOD);
	}
	else
	{
		val = pc + (val % IDX_MOD);
		ft_printf("{green} %d   a add {eoc}", val);
	}
	return (val);
}

static int	get_val_arg1(t_vm *vm, t_process *process, int param1)
{
	int ret;

	ret = param1;
	if (process->curent_instruction.type_arg[0][TYPE_2] == IND_CODE)
	{
//		ft_printf("param = %d  pc {%d}\t", param1, process->curent_pc);
		param1 = calcule_add(param1 ,process->curent_pc);//  % IDX_MOD;
//		ft_printf("lire dans la map a l'add = %d  \t", param1);
		ret = ft_read_indirect(vm, param1);
	}
	else if (process->curent_instruction.type_arg[0][TYPE_2] == DIR_CODE)
		ret = process->curent_instruction.vale_arg[0];
	return (ret);
}

BOOL		ft_ld(t_vm *vm, t_process *process)
{
	int				val;
	int				id_reg;

	val = get_val_arg1(vm, process, process->curent_instruction.vale_arg[0]);
	id_reg = process->curent_instruction.vale_arg[1] - 1;
	if (id_reg < 0 || id_reg > REG_NUMBER)
		return (F);
	process->reg[id_reg] = val;
	process->carry = (process->reg[id_reg]) ? F : T;


//	ft_printf("add = %d\n" , val);
//	ft_put_mem(vm->mem);
//	exit(0);



	return (T);
}
