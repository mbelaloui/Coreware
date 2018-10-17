/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:56:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/17 20:49:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_dell_vm(t_vm *vm)
{
	t_champ		*temp_dell;
	t_champ		*to_dell;
	int			pt;

	pt = 0;
	if (!vm->champs)
		return (F);
	temp_dell = vm->champs;
	while (temp_dell)
	{
		to_dell = temp_dell;
		temp_dell = temp_dell->next;
		ft_dell_champ(&(to_dell));
		pt++;
	}
	ft_free_optab(vm->op_tab);
	return (T);
}
