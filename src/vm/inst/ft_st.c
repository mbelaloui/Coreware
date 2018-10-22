/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 20:01:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** voir leaks
** ************************************************************************* **
*/

int	ft_st(t_vm *vm, t_process *process)
{
	int				id_reg_src;
	int				id_reg_dest;
	int				val;
	int				add;

	id_reg_src = process->curent_instruction.vale_arg[0] - 1;
	if (!ft_is_good_id_reg(id_reg_src))
		return (F);
	val = process->reg[id_reg_src];
	if (process->curent_instruction.type_arg[1][TYPE_2] == REG_CODE)
	{
		id_reg_dest = process->curent_instruction.vale_arg[1] - 1;
		if (!ft_is_good_id_reg(id_reg_dest))
			return (F);
		process->reg[id_reg_dest] = val;
	}
	else if (process->curent_instruction.type_arg[1][TYPE_2] == IND_CODE)
	{
		add = ft_calcule_add(process->curent_instruction.vale_arg[1],
	process->curent_pc);
		ft_put_to_mem(add, val, process, vm);
	}
	return (T);
}
