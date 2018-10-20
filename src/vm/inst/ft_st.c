/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/20 17:27:49 by mbelalou         ###   ########.fr       */
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
	int				id_reg_src;
	int				id_reg_dest;
	int				reg_src;
	int				add;

	id_reg_src = process->curent_instruction.vale_arg[0] - 1;
	
	reg_src = process->reg[id_reg_src];
	if (process->curent_instruction.type_arg[1][TYPE_2] == REG_CODE)
	{
		id_reg_dest = process->curent_instruction.vale_arg[1] - 1;

		process->reg[id_reg_dest] = reg_src;

	}
	else if (process->curent_instruction.type_arg[1][TYPE_2] == IND_CODE)
	{
		if (process->curent_instruction.vale_arg[1] > MEM_SIZE)
			add = (process->curent_instruction.vale_arg[1])
			+ process->curent_pc;
		else
			add = process->curent_pc + process->curent_instruction.vale_arg[1]
			% IDX_MOD;

/*
ft_printf("pc = [%d] to_val [%d] wante to go to {%d} [val %% = %d] add = {%d}\n",
		process->curent_pc,
		process->curent_instruction.vale_arg[1],
		process->curent_pc + process->curent_instruction.vale_arg[1] % MEM_SIZE,
		process->curent_instruction.vale_arg[1] % IDX_MOD,
		add);
*/
		ft_put_to_mem(add % MEM_SIZE, reg_src, process, vm);
	}
	return (T);
}
