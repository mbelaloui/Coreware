/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 19:49:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_process	*ft_new_process(int id_parent, int add_start)
{
	t_process *ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id_parent = id_parent;
	ret->pc = add_start;
	ret->carry = 0;
	ret->time_to_exe = 0;
	ft_bzero(ret->reg, sizeof(ret->reg));
	ft_bzero((&ret->curent_instruction), sizeof(ret->curent_instruction));
	ret->reg[0] = id_parent;
	ret->next = NULL;
	return (ret);
}
