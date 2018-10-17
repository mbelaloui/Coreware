/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 20:36:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** voir leaks
** ************************************************************************* **
*/

BOOL	ft_st(t_vm *vm, t_process *process)
{
	unsigned char	*tab;
	int				id_reg_src;
	int				max_print;
	int				reg_src;
	int				pt;

	tab = NULL;
	id_reg_src = process->curent_instruction.vale_arg[0] - 1;
	reg_src = process->reg[id_reg_src];
	if (process->curent_instruction.type_arg[1] == REG_CODE)
		process->reg[process->curent_instruction.vale_arg[1]] = reg_src;
	else if (process->curent_instruction.type_arg[1] == IND_CODE)
	{
		tab = ft_int_to_byts((unsigned)reg_src, DIR_SIZE);
		pt = (process->pc + (process->curent_instruction.vale_arg[1])
		- (DIR_SIZE) - 1) % MEM_SIZE;
		max_print = pt + DIR_SIZE;
		while (pt < max_print)
		{
			vm->mem[pt % MEM_SIZE][MEM_SRC] = tab[DIR_SIZE - (max_print - pt)];
			vm->mem[pt++ % MEM_SIZE][MEM_DESC] = process->id_parent;
		}
		free(tab);
	}
	return (T);
}
