/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_survivor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:34:46 by mint              #+#    #+#             */
/*   Updated: 2018/10/19 22:46:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
**	a testere rigoureusement   a optimiser  enlever le system de is_alive
**	et faire plus tot des free a la palce
**	ft_printf("process id =%d  pc =%d \n",
**	list_process->id_parent , list_process->pc);
**  renvoie le nbr de live fait apres avoir clean la liste des process
** ************************************************************************* **
*/

int	ft_check_survivor(t_process *list_process, t_vm *vm)
{
	int total_live;
	int live_cycle;

	live_cycle = vm->total_live_cycle;
	vm->total_live_cycle = 0;
	total_live = 0;
	if (!list_process)
		return (-1);
	while (list_process)
	{
		total_live += list_process->nbr_live;
		if (!list_process->nbr_live)
		{
			ft_rest_color(vm, list_process);
			list_process->a_live = F;
		}
		else
			list_process->nbr_live = 0;
		list_process = list_process->next;
	}
	vm->head_list_process = ft_kill_process(vm->head_list_process);
	return ((live_cycle) ? total_live : 0);
}
