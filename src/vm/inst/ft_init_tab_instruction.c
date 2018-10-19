/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_instruction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:39:24 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 13:46:11 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

void	ft_init_tab_instruction(BOOL (*action_instructions[NBR_OP])(t_vm *vm, t_process *process))
{
	(void)(action_instructions);

	action_instructions[0] = &ft_null;
	action_instructions[1] = &ft_live;//
	action_instructions[2] = &ft_ld;//
	action_instructions[3] = &ft_st;//
	action_instructions[4] = &ft_add;//
	action_instructions[5] = &ft_sub;//
	action_instructions[6] = &ft_and;//
	action_instructions[7] = &ft_or;//
	action_instructions[8] = &ft_xor;//
	action_instructions[9] = &ft_zjmp;//
	action_instructions[10] = &ft_ldi;//
	action_instructions[11] = &ft_sti;//
	action_instructions[12] = &ft_fork;//
	action_instructions[13] = &ft_lld;//
	action_instructions[14] = &ft_lldi;//
	action_instructions[15] = &ft_lfork;//
	action_instructions[16] = &ft_aff;//
}