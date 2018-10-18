/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:36:11 by mint              #+#    #+#             */
/*   Updated: 2018/10/18 19:05:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

void	ft_rest_color(t_vm *vm, t_process *process)
{

//	ft_printf("process id_parent [%d]   pc [%d]   curent pc [%d]\n", process->id_parent, process->pc, process->curent_pc);
	if (process->curent_instruction.id_opr != 0)
		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC] -= NULL_COLOR;
	else
		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC] -= REVERS_COLOR;
//		vm->mem[((process->curent_pc) % MEM_SIZE)][MEM_DESC] -= REVERS_COLOR;
//	else 
//		
	
//	ft_put_mem(vm->mem);
//	exit(0);
	(void)vm;
}
