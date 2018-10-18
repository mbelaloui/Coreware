/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 18:40:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_process	*ft_new_process(int num_parent, int add_start, int pos)
{
	t_process *ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id_parent = pos;
	ret->pc = add_start;
	ret->curent_pc = ret->pc;
	ret->carry = 0;
	ret->time_to_exe = 0;
	ft_bzero(ret->reg, sizeof(ret->reg));
	ft_bzero((&ret->curent_instruction), sizeof(ret->curent_instruction));
	ret->curent_instruction.id_opr = -1;
	ret->reg[0] = num_parent;
	//ret->color_start = 0;
	ret->nbr_live = 0;
	ret->a_live = T;
	ret->next = NULL;
	return (ret);
}
