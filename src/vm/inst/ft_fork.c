/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 20:15:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** fonction fini
** ************************************************************************* **
*/

BOOL	ft_fork(t_vm *vm, t_process *process)
{
	t_process	*new_process;
	int			new_pc;
	int			arg;

	arg = process->curent_instruction.vale_arg[0];
	new_pc = arg + process->curent_pc % MEM_SIZE;
	new_process = ft_copie_process(new_pc % IDX_MOD, process);
	ft_add_process(new_process, &(vm->head_list_process));
	return (T);
}
