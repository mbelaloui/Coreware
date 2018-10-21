/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_vale_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:24:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/21 01:40:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** pour aue sa soit plus coherent si non on aurait pu enlever cette fonction
*/

static int	get_reg_val_arg(int val)
{
	return (val);
}

static int	get_ind_val_arg(int val1, int val2)
{
//	ft_printf("[%.2x] [%.2x]  1 val = %d\n", val1, val2, ((val1 << 8) | val2));
	//exit(0);
	return ((short)((val1 << 8) | val2));
}

static int	get_dir_val_arg(int val1, int val2, int val3, int val4)
{
	return ((((((val1 << 8) | val2) << 8) | val3) << 8) | val4);
}

int			ft_set_vale_arg(t_vm *vm, int pc, t_opr_exe *opr)
{
	int param;

	param = 0;
	while (param < opr->nbr_param)
	{
		if (opr->size_arg[param] == REG_SIZE)
			opr->vale_arg[param] = get_reg_val_arg(vm->mem[pc][MEM_SRC]);
		else if (opr->size_arg[param] == IND_SIZE)
			opr->vale_arg[param] = get_ind_val_arg(vm->mem[pc][MEM_SRC],
			vm->mem[pc + 1][MEM_SRC]);
		else if (opr->size_arg[param] == DIR_SIZE)
			opr->vale_arg[param] = get_dir_val_arg(vm->mem[pc][MEM_SRC],
			vm->mem[pc + 1][MEM_SRC], vm->mem[pc + 2][MEM_SRC],
			vm->mem[pc + 3][MEM_SRC]);
		pc = ((pc + opr->size_arg[param]) % MEM_SIZE);
		param++;
	}
	return (pc);
}
