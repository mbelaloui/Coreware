/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_survivor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:34:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/17 21:38:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**	a testere rigoureusement   a optimiser  enlever le system de is_alive
**	et faire plus tot des free a la palce
**	ft_printf("process id =%d  pc =%d \n",
**	list_process->id_parent , list_process->pc);
** ************************************************************************* **
*/

BOOL	ft_check_survivor(t_process *list_process, t_vm *vm)
{
	int id_process;

	if (!list_process)
		return (F);
	id_process = 0;
	while (list_process)
	{
		if (!list_process->nbr_live)
		{
			ft_rest_color(vm, list_process);
			list_process->a_live = F;
		//	ft_temporize(15);
			ft_put_mem(vm->mem);
			id_process--;
		}
		else
		{
			list_process->nbr_live = 0;
			id_process++;
		}
		list_process = list_process->next;
//		ft_printf("   life   [%d]", list_process->nbr_live);
//		exit(0);
	}
	return (T);
	//	id_process a la fin doit etre == a la taill de la list_process
}