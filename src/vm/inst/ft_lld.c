/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:42 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 12:58:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** a tester
** ************************************************************************* **
*/

BOOL	ft_lld(t_vm *vm, t_process *process)
{
	unsigned char	tab[4];
	int				add_val;
	int				val;
	int				id_reg;

	id_reg = process->curent_instruction.vale_arg[1] - 1;
	val = process->curent_instruction.vale_arg[0];
	if (process->curent_instruction.type_arg[0][type_2] == IND_CODE)
	{
		add_val = process->curent_pc + val;
		tab[0] = (process->curent_instruction.vale_arg[0] == 1) ? -1 : 0;
		tab[1] = (process->curent_instruction.vale_arg[0] == 1) ? -1 : 0;
		tab[2] = vm->mem[(add_val + 0) % MEM_SIZE][MEM_SRC];
		tab[3] = vm->mem[(add_val + 1) % MEM_SIZE][MEM_SRC];
		val = ft_byts_to_int(tab);
	}
	else
		process->carry = (!val) ? T : F;
	process->reg[id_reg] = val;
	return (T);
}
