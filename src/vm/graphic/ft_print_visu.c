/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_visu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:51:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/20 18:58:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void		print_player(WINDOW *player, int nb)
{
	wmove(player, 0, 0);
	mvwprintw(player, 1, 4, "Champion %d :\t\t%s", nb, "name");
	mvwprintw(player, 2, 4, "Last live :\t\t\t%d (%d)", 0, 0);
	mvwprintw(player, 3, 4, "Size :\t\t\t%d", 0);
	mvwprintw(player, 4, 4, "Live :\t\t\t%d", 0);
	mvwprintw(player, 5, 4, "Processes :\t\t\t%d", 0);
	wrefresh(player);
}

static void		print_stats(WINDOW *stats, int time)
{
	wmove(stats, 0, 0);
	mvwprintw(stats, 1, 4, "Cycle :\t\t\t%d", 0);
	mvwprintw(stats, 3, 4, "Cycle delta :\t\t%d", 0);
	mvwprintw(stats, 2, 4, "Cycles to die :\t\t%d/%d", 0, 0);
	mvwprintw(stats, 4, 4, "Processes :\t\t\t%d", 0);
	mvwprintw(stats, 5, 4, "Number of lives :\t\t%d/%d", 0, 0);
	mvwprintw(stats, 6, 4, "Checks :\t\t\t%d/%d", 0, 0);
	mvwprintw(stats, 7, 4, "Cycle per second :\t\t%d", time);
	wrefresh(stats);
}

void		esc_visu(t_vm *vm)
{
	delwin(vm->map);
	delwin(vm->stats);
	delwin(vm->player_1);
	if (vm->nbr_champ > 1)
		delwin(vm->player_2);
	if (vm->nbr_champ > 2)
		delwin(vm->player_3);
	if (vm->nbr_champ > 3)
		delwin(vm->player_4);
	endwin();
//	exit(1);
}

void		print_all(t_vm *vm, int time)
{
	print_map(vm);
	print_player(vm->player_1, 1);
	if(vm->nbr_champ > 1)
		print_player(vm->player_2, 2);
	if(vm->nbr_champ > 2)
		print_player(vm->player_3, 3);
	if(vm->nbr_champ > 3)
		print_player(vm->player_4, 4);
	print_stats(vm->stats, time);
}

void		ft_print_visu(t_vm *vm)
{
	int		j;
	char	c;

	j = 1;
	print_all(vm, vm->speed);
	c = getch();
	if (c == 27)
		esc_visu(vm);
	else if (c == '-' || c == '+')
	{
		if (c == '+' && vm->speed > 1)
			vm->speed -= 1000000;
		else if (c == '-' && vm->speed < 19000001)
			vm->speed += 1000000;
		mvprintw(64, 204, "Vitesse :\t%02d/20", 20 - (vm->speed / 1000000));
	}
	else if (c == 32 || c == '=')
		visu_pause(vm);
	j = 1;
	while (j < vm->speed)
		j++;
//	esc_visu(vm);
	//endwin();
}
