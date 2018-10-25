/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:36:11 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 14:47:46 by mbelalou         ###   ########.fr       */
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
	if (process->curent_instruction.id_opr == 0)
	{
		if (vm->mem[process->curent_pc][MEM_DESC] == REVERS_COLOR)
			vm->mem[process->curent_pc][MEM_DESC] -= NULL_COLOR;
	}
	else if (process->curent_instruction.id_opr > 0)
	{
		if (vm->mem[process->curent_pc][MEM_DESC] > REVERS_COLOR)
			vm->mem[process->curent_pc][MEM_DESC] -= NULL_COLOR;
	}
}
