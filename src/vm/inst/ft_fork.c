/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:46:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 11:58:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	copie_reg(int tab_dest[], int tab_src[], int size)
{
	int pt;

	pt = 0;
	while (pt < size)
	{
		tab_dest[pt] = tab_src[pt];
		pt++;
	}
}

t_process	*ft_copie_process(int add_start, t_process *process)
{
	t_process *ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id_parent = process->id_parent;
	ret->pc = add_start;
	ret->curent_pc = ret->pc;
	ret->carry = process->carry;
	ret->time_to_exe = 0;
	ft_bzero(ret->reg, sizeof(ret->reg));
	ft_bzero((&ret->curent_instruction), sizeof(ret->curent_instruction));
	ret->curent_instruction.id_opr = -1;


	copie_reg(ret->reg, process->reg, REG_NUMBER);
	ret->reg[0] = process->reg[0];
	ret->color_start = process->color_start;

	ret->nbr_live = 0;
	ret->a_live = T;
	ret->next = NULL;
	return (ret);
}


/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_fork(t_vm *vm, t_process *process)
{
/*
	t_process	*new_process;

	int new_pc = process->curent_instruction.vale_arg[0] + process->curent_pc % MEM_SIZE;  // % IDX_MOD 

	ft_copie_process(new_pc, process);
*/
//	ft_add_process(new_pc, vm->list_process);
/*	t_op	*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
	ft_put_opr_exe(&(process->curent_instruction), op_tab);
*/	(void) vm;
	(void) process;
//	ft_free_optab(op_tab);
	return (T);
}