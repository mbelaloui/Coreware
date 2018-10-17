/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:20 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 20:16:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** fonction a tester 
** ************************************************************************* **
*/

BOOL	ft_lfork(t_vm *vm, t_process *process)
{
	t_process	*new_process;
	int			new_pc;
	int			arg;

	arg = process->curent_instruction.vale_arg[0];
	new_pc = arg + process->curent_pc % MEM_SIZE;
	new_process = ft_copie_process(new_pc, process);
	ft_add_process(new_process, &(vm->head_list_process));
	return (T);
}