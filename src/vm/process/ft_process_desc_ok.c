/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_desc_ok.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:25:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 18:39:46 by mbelalou         ###   ########.fr       */
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
**	size_inst = ft_set_size_arg(opr_exe, op_tab) + 2;
**						 // +2 pour les oct de opr + ocp
**}
*/

void	ft_set_color_inst(t_vm *vm, int start, int len, int id_process)
{
//	if (vm->mem[start][MEM_DESC] == id_process)
	{
		while (len)
		{
			vm->mem[start][MEM_DESC] = id_process + ACTUAL_ACTION;
			len--;
			start++;
		}
	}
}

/*
BOOL	is_good(int ref, int param, int pos)
{
	ft_printf("pos %d\nref \t%.9b\nprm \t%0.9b\t\n...\t%0.9b\n\n",pos, ref, param, param);

	return (T);
}
*/
BOOL	is_valide_desc_arg(t_vm *vm, t_opr_exe *opr)
{
	int pt;

	pt = 0;
	while (pt < opr->nbr_param)
	{

//		ft_printf("id _opr [%d]{%s} \n\n\n", opr->id_opr, vm->op_tab[opr->id_opr]->name);

		if (!(vm->op_tab[opr->id_opr]->param & opr->type_arg[pt][type_1]))
		{
//			ft_printf("hna \n\n\n");
			opr->id_opr = 0;
			return (F);
		}
		pt++;
	}
//	exit(0);
	return (T);
}

int	ft_process_desc_ok(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
	int temp_pc;
	int size_inst;
	int start;

	start = process->pc;
	temp_pc = (process->pc + 1) % MEM_SIZE;
//	ft_printf("pc<start> [%d] temp_pc[%d]   \n", start, temp_pc);

	opr_exe->nbr_param = get_nbr_param(vm->mem[temp_pc][MEM_SRC]);
	ft_set_desc_arg(vm->mem[temp_pc][MEM_SRC], opr_exe->nbr_param,
		opr_exe);
	if (!is_valide_desc_arg(vm, opr_exe))
		return (start);
	temp_pc = (temp_pc + 1) % MEM_SIZE;
	size_inst = ft_set_size_arg(opr_exe, op_tab) + 2;

	//ft_set_color_inst(vm, start, size_inst, process->id_parent);
	process->pc = ft_set_vale_arg(vm, temp_pc, opr_exe);

	//ft_printf("pc<start> [%d] temp_pc[%d]   \n", start, temp_pc);
	//ft_put_opr_exe(opr_exe, vm->op_tab);

	return (0);
}
