/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:53 by mint              #+#    #+#             */
/*   Updated: 2018/10/15 18:20:49 by mbelalou         ###   ########.fr       */
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
	int val_arg_1 = process->curent_instruction.vale_arg[0];
	int val_arg_2 = process->curent_instruction.vale_arg[1];
	int id_reg = process->curent_instruction.vale_arg[2] - 1;
	int pt;
	unsigned char	tab[DIR_SIZE];
	int				max_read;

	pt = ((process->curent_pc + val_arg_1) % IDX_MOD) + val_arg_2;
	if (val_arg_1)
		pt--;
	max_read = (pt + DIR_SIZE);
	while (pt < max_read)
	{
		tab[DIR_SIZE - (max_read - pt)] = vm->mem[pt][MEM_SRC];
		vm->mem[pt][MEM_DESC] = process->id_parent;
		pt = (pt + 1);
	}
	process->reg[id_reg] = ft_byts_to_int(tab);
	if (process->reg[id_reg])
		process->carry = 0;
	else
		process->carry = 1;
	return (T);
}