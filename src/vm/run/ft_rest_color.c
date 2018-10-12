/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rest_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:36:11 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 11:36:34 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

void	ft_rest_color(t_vm *vm, t_process *list_process)
{
	int			start;

	if (list_process->a_live)
	{
		start = list_process->color_start;
		if (start > list_process->pc)
			vm->mem[((start - 2) % MEM_SIZE)][MEM_DESC] = NULL_COLOR;
		else
		{
			while (start < list_process->pc)
			{
				if (list_process->curent_instruction.id_opr == NULL_COLOR)
				{
					if (vm->mem[((start) % MEM_SIZE)][MEM_DESC] == PT_COLOR)
						vm->mem[((start) % MEM_SIZE)][MEM_DESC] = NULL_COLOR;
					else
						vm->mem[start][MEM_DESC] = PT_COLOR;
				}
				else
				{
					if (vm->mem[((start - 1) % MEM_SIZE)][MEM_DESC] == PT_COLOR)
						vm->mem[((start - 1) % MEM_SIZE)]
						[MEM_DESC] = NULL_COLOR;
					else if (((start - 1) % MEM_SIZE) == -1)
						vm->mem[(MEM_SIZE - 1)][MEM_DESC] = NULL_COLOR;
					vm->mem[start][MEM_DESC] = list_process->id_parent;
				}
				start++;
			}
		}
	}
}
