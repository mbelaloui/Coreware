/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_desc_ko.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:27:04 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:56:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int	ft_process_desc_ko(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
	int temp_pc;
	int start;

	start = process->pc;
	temp_pc = (process->pc + 1) % MEM_SIZE;
	opr_exe->nbr_param = 1;
	opr_exe->type_arg[0][TYPE_1] = T_DIR_P1;
	opr_exe->type_arg[0][TYPE_2] = DIR_CODE;
	opr_exe->size_arg[0] = op_tab[opr_exe->id_opr]->size_label;
	process->pc = ft_set_vale_arg(vm, temp_pc, opr_exe);
	return (start);
}
