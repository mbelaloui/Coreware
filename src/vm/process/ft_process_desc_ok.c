/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_desc_ok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:25:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 11:12:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		get_nbr_param(int desc)
{
	int cp;

	cp = 0;
	while (desc & MASK_PARAM)
	{
		cp++;
		desc = desc << 2;
	}
	return (cp);
}

/*
**void	ft_process_desc_ok(t_opr_exe *opr_exe , t_op *op_tab[NBR_OP],
**	t_vm *vm, t_process *process)
**
**	ft_byts_to_int();
** //	ft_printf(" operation name  [%s]   OCP [%s] {%.8b} \n",
** //		op_tab[opr_exe->id_opr]->name, "need description",
** //		vm->mem[process->pc][MEM_SRC]);
**
**	int ocp =  vm->mem[process->pc][MEM_SRC];//  asuprimer plus tard
**	process->pc = (process->pc + 1) % MEM_SIZE; // already got the description
**
**	//int max = get_size_desc(opr_exe->id_opr, ocp, op_tab);
**
**	opr_exe->nbr_param = get_nbr_param(ocp);
**
**	ft_set_desc_arg(ocp, opr_exe->nbr_param , opr_exe);
**	// il faut imperativement appler la fonction
**			<set_desc_arg> avant <set_size_arg>
** 	ft_set_size_arg(opr_exe, op_tab);
**	process->pc = ft_set_vale_arg(vm, process->pc, opr_exe);
**
**	ft_put_opr_exe(opr_exe, op_tab);
**
**	ft_printf("pc = %d {eoc}\n", process->pc);
**}
*/

void	ft_process_desc_ok(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
	opr_exe->nbr_param = get_nbr_param(vm->mem[process->pc][MEM_SRC]);
	ft_set_desc_arg(vm->mem[process->pc][MEM_SRC], opr_exe->nbr_param,
	opr_exe);
	ft_set_size_arg(opr_exe, op_tab);
	process->pc = (process->pc + 1) % MEM_SIZE;
	process->pc = ft_set_vale_arg(vm, process->pc, opr_exe);
}
