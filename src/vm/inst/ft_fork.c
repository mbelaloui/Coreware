/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/21 01:26:40 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** fonction fini
** ************************************************************************* **
*/

int			ft_calcule_add(int val, int pc)//////////////
{
	int ret;

	ret = (val % IDX_MOD) + pc;
	return ((ret < 0) ? ((MEM_SIZE + ret) % MEM_SIZE) : (ret % MEM_SIZE));
}

BOOL	ft_fork(t_vm *vm, t_process *process)
{
	t_process	*new_process;
	int			new_pc;
	int			val;

	val = process->curent_instruction.vale_arg[0];
	new_pc = ft_calcule_add(val, process->curent_pc);
	new_process = ft_copie_process(new_pc, process);
	ft_add_process(new_process, &(vm->head_list_process));
	return (T);
}
