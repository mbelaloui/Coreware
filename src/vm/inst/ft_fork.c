/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 17:28:21 by mbelalou         ###   ########.fr       */
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
	int			val;

	val = process->curent_instruction.vale_arg[0];
//	ft_printf("fork add [%d]\n", val);
	val = (val > MEM_SIZE) ? (MEM_SIZE + val) - MEM_SIZE : val % IDX_MOD;
	new_pc = (val + process->curent_pc) % MEM_SIZE;
	new_process = ft_copie_process(new_pc, process);
	ft_add_process(new_process, &(vm->head_list_process));
//	ft_printf("fork add [%d]\n", val);
//	exit(0);
	return (T);
}
