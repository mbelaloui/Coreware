/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_desc_ko.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:27:04 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 10:47:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** void	ft_process_desc_ko(t_opr_exe *opr_exe , t_op *op_tab[NBR_OP],
**	t_vm *vm, t_process *process)
** {
**		ft_printf(" operation name  [%s]   OCP [%s] {%.8b} \n",
**		op_tab[opr_exe->id_opr]->name, "don't need description",
**		vm->mem[process->pc][MEM_SRC]);
**
**
**	opr_exe->nbr_param = 1;
** 	opr_exe->size_arg[0] = op_tab[opr_exe->id_opr]->size_label;
**	process->pc = ft_set_vale_arg(vm, process->pc, opr_exe);
**	ft_put_opr_exe(opr_exe, op_tab);
**	ft_printf("pc = %d {eoc}\n", process->pc);
**
**}
*/

void	ft_process_desc_ko(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
	opr_exe->nbr_param = 1;
	opr_exe->size_arg[0] = op_tab[opr_exe->id_opr]->size_label;
	process->pc = ft_set_vale_arg(vm, process->pc, opr_exe);
}
