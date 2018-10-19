/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_visu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:51:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 19:54:13 by mbelalou         ###   ########.fr       */
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

static void		print_stats(WINDOW *stats, int nb, int time)
{
	wmove(stats, 0, 0);
	mvwprintw(stats, 1, 4, "Cycle :\t\t\t%d", nb);
	mvwprintw(stats, 3, 4, "Cycle delta :\t\t%d", 0);
	mvwprintw(stats, 2, 4, "Cycles to die :\t\t%d/%d", 0, 0);
	mvwprintw(stats, 4, 4, "Processes :\t\t\t%d", 0);
	mvwprintw(stats, 5, 4, "Number of lives :\t\t%d/%d", 0, 0);
	mvwprintw(stats, 6, 4, "Checks :\t\t\t%d/%d", 0, 0);
	mvwprintw(stats, 7, 4, "Cycle per second :\t\t%d", time / 1000000);
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
	exit(1);
}


void		visu_pause(t_vm *vm)
{
	char	c;

	mvprintw(64, 226, "	PAUSE");
	while (1)
	{
		c = getch();
		if (c == 32)
			break ;
		if (c == 27)
			esc_visu(vm);
	}
	mvprintw(64, 226, "	     ");
}

void		ft_print_visu(t_vm *vm)
{
	int i = 0;
	int	time = 1;
	while (i < 100000)
	{
		int		j;
		char	c;

		j = 1;
	//	print_maps(line, map);
		print_player(vm->player_1, 1),
		print_player(vm->player_2, 2),
		print_player(vm->player_3, 3),
		print_player(vm->player_4, 4),
		print_stats(vm->stats, i, time);
		c = getch();
		if (c == 27)
			esc_visu(vm);
		else if (c == '-' || c == '+')
		{
			if (c == '+' && time > 1)
				time -= 1000000;
			else if (c == '-' && time < 19000001)
				time += 1000000;
			mvprintw(64, 204, "Vitesse :\t%02d/20", 20 - (time / 1000000));
		}
		else if (c == 32 || c == '=')
			visu_pause(vm);
		j = 1;
		while (j < time)
			j++;
	i++;
	}
}