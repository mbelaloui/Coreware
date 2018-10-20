/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_val_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:20:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/20 13:49:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"


int		get_val_reg(t_process *process, int param)
{
	//ft_printf(" param [%d] = {%d}\n", param, process->reg[param - 1]);
	return (process->reg[param - 1]);
}

int		ft_get_val_param(int param, t_process *process, int type)
{
	if (type == REG_CODE)
		return (get_val_reg(process, param));
/*	else if (type == IND_CODE)
		return (get_ind());
	else if (type == DIR_CODE)
		return (get_dir());
	else
*/		return (0);
}