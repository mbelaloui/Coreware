/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/20 16:04:40 by mbelalou         ###   ########.fr       */
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
	new_pc = (val + process->curent_pc) % IDX_MOD;
	new_process = ft_copie_process(new_pc, process);
/*
	ft_get_next_instuction(&new_process->curent_instruction, vm,
				new_process, vm->op_tab);
*/
	ft_add_process(new_process, &(vm->head_list_process));
//	ft_printf("fork add [%d]\n", val);
//	exit(0);
	return (T);
}
