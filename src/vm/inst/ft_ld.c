/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 19:59:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** fonction a tester fini
** ************************************************************************* **
*/

BOOL	ft_ld(t_vm *vm, t_process *process)
{
//	unsigned char	tab[4];
	int				add_val;
	int				val;
	int				id_reg;

	add_val = process->curent_instruction.vale_arg[0];
	id_reg = process->curent_instruction.vale_arg[1] - 1;
	val = 0;

	if (process->curent_instruction.type_arg[0] == IND_CODE)
	{
		add_val = process->curent_pc + (val % IDX_MOD);
		val = ft_read_indirect(vm, add_val);
/*
		tab[0] = vm->mem[(add_val + 0) % MEM_SIZE][MEM_SRC];
		tab[1] = vm->mem[(add_val + 1) % MEM_SIZE][MEM_SRC];
		tab[2] = vm->mem[(add_val + 2) % MEM_SIZE][MEM_SRC];
		tab[3] = vm->mem[(add_val + 3) % MEM_SIZE][MEM_SRC];
		val = ft_byts_to_int(tab);
*/
	}
	else if (process->curent_instruction.type_arg[0] == DIR_CODE)
	{
		val = add_val;
		process->carry = (!val) ? T : F;
	}
	process->reg[id_reg] = val;
	return (T);
}
