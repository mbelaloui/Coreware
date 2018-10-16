/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:16 by mint              #+#    #+#             */
/*   Updated: 2018/10/16 16:41:23 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**
** ************************************************************************* **
*/

BOOL	ft_and(t_vm *vm, t_process *process)
{
	int id_reg_1 = process->curent_instruction.vale_arg[0] - 1;
	int id_reg_2 = process->curent_instruction.vale_arg[1] - 1;
	int id_reg_3 = process->curent_instruction.vale_arg[2] - 1;

	// is_reg_ok() ??

	int reg1 = process->reg[id_reg_1] ;
	int reg2 = process->reg[id_reg_2] ;
/*
	int temp_val_res;

	temp_val_res = ((reg1 & 0xff000000) >> 24) & ((reg2 & 0xff000000) >> 24);

temp_val_res = temp_val_res << 8;

	temp_val_res = temp_val_res | (((reg1 & 0x00ff0000) >> 16) & ((reg2 & 0x00ff0000) >> 16));

temp_val_res = temp_val_res << 8;

	temp_val_res = temp_val_res | (((reg1 & 0x0000ff00) >> 8) & ((reg2 & 0x0000ff00) >> 8));

temp_val_res = temp_val_res << 8;

	temp_val_res = temp_val_res | (((reg1 & 0x000000ff)) & ((reg2 & 0x000000ff)));

	process->reg[id_reg_3] = temp_val_res ;

*/

	process->reg[id_reg_3] = reg1 & reg2;

	if (process->reg[id_reg_3])
		process->carry = 0;
	else
		process->carry = 1;


//	t_op	*op_tab[NBR_OP];

//	ft_get_op_tab(op_tab);
//	ft_put_opr_exe(&(process->curent_instruction), op_tab);
	(void) vm;
//	ft_free_optab(op_tab);
	return (T);
}