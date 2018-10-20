/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:20 by mint              #+#    #+#             */
/*   Updated: 2018/10/20 17:13:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_sub(t_vm *vm, t_process *process)
{
	int id_reg_1;
	int id_reg_2;
	int id_reg_3;
	int reg1;
	int reg2;

	ft_printf("/*************************** \\ \n");
	ft_printf("param 1 = [%d, %d, %d]  pc = %d \n",
		id_reg_1 = process->curent_instruction.vale_arg[0],
		id_reg_2 = process->curent_instruction.vale_arg[1],
		id_reg_3 = process->curent_instruction.vale_arg[2],
		process->curent_pc);
	if (id_reg_3 == 190056705)
	{
		vm->mem[++process->curent_pc][MEM_DESC] =  0;
		vm->mem[++process->curent_pc][MEM_DESC] =  0;
		vm->mem[++process->curent_pc][MEM_DESC] =  0;
		vm->mem[++process->curent_pc][MEM_DESC] =  0;
		vm->mem[++process->curent_pc][MEM_DESC] =  0;
		vm->mem[++process->curent_pc][MEM_DESC] =  0;
		ft_put_mem(vm->mem);
	}
	id_reg_1 = process->curent_instruction.vale_arg[0] - 1;
	id_reg_2 = process->curent_instruction.vale_arg[1] - 1;
	id_reg_3 = process->curent_instruction.vale_arg[2] - 1;
	reg1 = process->reg[id_reg_1];
	reg2 = process->reg[id_reg_2];
	process->reg[id_reg_3] = reg1 - reg2;
	process->carry = (process->reg[id_reg_3]) ? F : T;
	(void)vm;
	return (T);
}
