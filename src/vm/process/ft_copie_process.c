/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copie_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:17:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 22:08:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	copie_reg(int tab_dest[], int tab_src[], int size)
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
	ret->nbr_live = 1;
	ret->a_live = T;
	ret->next = NULL;
	return (ret);
}
