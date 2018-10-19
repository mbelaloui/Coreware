/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 14:19:52 by mbelalou         ###   ########.fr       */
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
	int				reg_src;
	int				add;

	tab = NULL;
	id_reg_src = process->curent_instruction.vale_arg[0] - 1;
	reg_src = process->reg[id_reg_src];
	if (process->curent_instruction.type_arg[1][TYPE_2] == REG_CODE)
		process->reg[process->curent_instruction.vale_arg[1]] = reg_src;
	else if (process->curent_instruction.type_arg[1][TYPE_2] == IND_CODE)
	{
		add = (process->pc + (process->curent_instruction.vale_arg[1])
		- (DIR_SIZE) - 1) % MEM_SIZE;
		ft_put_to_mem(add, reg_src, process, vm);
	}
	return (T);
}
