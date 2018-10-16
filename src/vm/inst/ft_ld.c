/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/16 17:48:42 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_ld(t_vm *vm, t_process *process)
{
	unsigned char	tab[4];
	int				add_val;
	int				val;

	if (process->curent_instruction.vale_arg[0] == 0)
		process->carry = 1;
	else
		process->carry = 0;
/*
	ft_printf(" process pc = %d    ", process->pc);
	ft_printf(" prev pc = %d    ", process->curent_pc);
*/
	if (process->curent_instruction.type_arg[0] == IND_CODE)
	{
		add_val = process->curent_pc + (process->curent_instruction.vale_arg[0] % IDX_MOD);
		tab[0] = vm->mem[(add_val + 0) % MEM_SIZE][MEM_SRC];
		tab[1] = vm->mem[(add_val + 1) % MEM_SIZE][MEM_SRC];
		tab[2] = vm->mem[(add_val + 2) % MEM_SIZE][MEM_SRC];
		tab[3] = vm->mem[(add_val + 3) % MEM_SIZE][MEM_SRC];
/*
		ft_printf("tab = %.2x      ", tab[0]);
		ft_printf("tab = %.2x      ", tab[1]);
		ft_printf("tab = %.2x      ", tab[2]);
		ft_printf("tab = %.2x    \n", tab[3]);
*/
		val = ft_byts_to_int(tab);
	}
	else
	{
		add_val = process->curent_instruction.vale_arg[0] % IDX_MOD;
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