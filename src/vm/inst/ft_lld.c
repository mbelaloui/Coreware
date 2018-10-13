/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:42 by mint              #+#    #+#             */
/*   Updated: 2018/10/13 21:49:02 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_lld(t_vm *vm, t_process *process)
{
	unsigned char	tab[4];
	int				add_val;
	int				val;

	if (process->curent_instruction.vale_arg[0])
		process->carry = 1;
	else
		process->carry = 0;
/*
	ft_printf(" process pc = %d    ", process->pc);
	ft_printf(" prev pc = %d    ", process->curent_pc);
*/
	if (process->curent_instruction.type_arg[0] == IND_CODE)
	{
		add_val = (process->curent_instruction.vale_arg[0] + process->curent_pc);
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = vm->mem[(add_val + 0) % MEM_SIZE][MEM_SRC];
		tab[3] = vm->mem[(add_val + 1) % MEM_SIZE][MEM_SRC];
		val = ft_byts_to_int(tab);
	}
	else if (process->curent_instruction.type_arg[0] == DIR_CODE)
	{
		add_val = (process->curent_instruction.vale_arg[0]);
		tab[3] = add_val & 0xff;
		add_val = add_val >> 8;
		tab[2] = add_val & 0xff;
		add_val = add_val >> 8;
		tab[1] = add_val & 0xff;
		add_val = add_val >> 8;
		tab[0] = add_val & 0xff;
		val = ft_byts_to_int(tab);
	}
	else
	{
		add_val = process->curent_instruction.vale_arg[0] % MEM_SIZE;
		val = add_val;
	}
/*
	ft_printf("address val = %d    ", add_val);
	ft_printf("val = %d ", val);

	ft_printf("reg num = %d ", val);
*/
	process->reg[process->curent_instruction.vale_arg[1] - 1] = val;
	return (T);
}
