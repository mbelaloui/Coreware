/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:47:48 by mint              #+#    #+#             */
/*   Updated: 2018/10/18 19:04:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** ************************************************************************* **
** a tester
** ************************************************************************* **
*/

BOOL	ft_live(t_vm *vm, t_process *process)
{
	t_champ	*pt_champ;
	int		live_for;

	process->nbr_live++;
	//if (process->curent_instruction.type_arg[0][type_2] == DIR_CODE)
	{
		//ft_put_mem(vm->mem);
		live_for = process->curent_instruction.vale_arg[0];
//		ft_printf("live for %d \n",
//			live_for);

//		ft_printf("2 \n");
		pt_champ = vm->champs;
//		ft_printf("1 \n");
		while (pt_champ)
		{
//			ft_printf("3  NUM = %d \n", pt_champ->num);

			if (pt_champ->num == live_for)
			{
//							ft_printf("4 \n");

				vm->id_last_a_live = live_for;
					return (T);
			//	break ;
			}
//			ft_printf("5 \n");

			pt_champ = pt_champ->next;
		}
		return (T);
	}
	(void)vm;
	return (F);
}
