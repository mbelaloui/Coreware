/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:29 by mint              #+#    #+#             */
/*   Updated: 2018/10/22 19:34:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**	fonction fini
** ************************************************************************* **
*/

int	ft_add(t_vm *vm, t_process *process)
{
	int id_reg_1;
	int id_reg_2;
	int id_reg_3;
	int reg1;
	int reg2;

	id_reg_1 = process->curent_instruction.vale_arg[0] - 1;
	if (!ft_is_good_id_reg(id_reg_1))
		return (F);
	id_reg_2 = process->curent_instruction.vale_arg[1] - 1;
	if (!ft_is_good_id_reg(id_reg_2))
		return (F);
	id_reg_3 = process->curent_instruction.vale_arg[2] - 1;
	if (!ft_is_good_id_reg(id_reg_3))
		return (F);
	reg1 = process->reg[id_reg_1];
	reg2 = process->reg[id_reg_2];
	process->reg[id_reg_3] = reg1 + reg2;
	process->carry = (process->reg[id_reg_3]) ? F : T;
	(void)vm;
	return (T);
}
