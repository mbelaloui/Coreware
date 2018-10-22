/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_visu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:10:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 15:10:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void		esc_visu(t_vm *vm, int i)
{
	if (i == 1)
	{
		nodelay(stdscr, FALSE);
		while (1)
			if (getch())
				break ;
	}
	delwin(vm->map);
	delwin(vm->border1);
	delwin(vm->border2);
	delwin(vm->border3);
	delwin(vm->border4);
	delwin(vm->stats);
	delwin(vm->player_1);
	if (vm->nbr_champ > 1)
		delwin(vm->player_2);
	if (vm->nbr_champ > 2)
		delwin(vm->player_3);
	if (vm->nbr_champ > 3)
		delwin(vm->player_4);
	endwin();
	if (i == 0)
		exit(1);
}