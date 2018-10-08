/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:20:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 10:20:46 by mbelalou         ###   ########.fr       */
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
	ft_bzero(ret->reg, sizeof(ret->reg));
	ret->reg[0] = id_parent;
	ret->next = NULL;
	return (ret);
}
