/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_visu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:51:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 17:20:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void		print_player(t_vm *vm, WINDOW *player, int nb)
{
	t_champ		*champ;
	int			pos_champ;

	champ = vm->champs;
	while (champ->next && nb != champ->pos)
		champ = champ->next;
	pos_champ = champ->pos - 1;
	wmove(player, 0, 0);
	mvwprintw(player, 1, 4, "Champion %d         : %.35s",
	nb, champ->name);
	mvwprintw(player, 2, 4, "Last live          : %d (%d)"
	"      ", vm->time_last_live[pos_champ],
	vm->time_total + vm->time - vm->time_last_live[pos_champ]);
	mvwprintw(player, 3, 4, "Live               : %d",
	vm->live[pos_champ]);
	mvwprintw(player, 4, 4, "Processes Owned    : %-5d",
	ft_get_nbr_process_ceated_by_champ(vm->head_list_process, champ->pos));
	mvwprintw(player, 5, 4, "Processes Working  : %-5d",
	ft_get_nbr_process_working_for_champ(vm->head_list_process, champ->num));
	wrefresh(player);
}

static void		print_stats(t_vm *vm, WINDOW *stats, int time)/// voir seb temp
{
	t_champ *win;

	win = get_winner(vm);
	wmove(stats, 0, 0);
	mvwprintw(stats, 1, 4, "Cycle              : %d",
	vm->time_total + vm->time);
	mvwprintw(stats, 3, 4, "Cycle delta        : %d",
	CYCLE_DELTA);
	mvwprintw(stats, 2, 4, "Cycles to die      : %-4d/%4d",
	vm->time, vm->cycle_to_die);
	mvwprintw(stats, 4, 4, "Processes          : %-9d",
	ft_get_size_list_process(vm->head_list_process));
	mvwprintw(stats, 5, 4, "Number of lives    : %-5d/%-2d",
	ft_somme_tab(vm->live, MAX_PLAYERS), NBR_LIVE);
	mvwprintw(stats, 6, 4, "Checks             : %-2d/%2d", vm->check,
	MAX_CHECKS);
	mvwprintw(stats, 7, 4, "Actually winner    : %-35.35s",
	(win) ? win->name : "NONNE XD hihihi");
	wrefresh(stats);
	(void)time;
}

static void		print_border(WINDOW *border, char *str, int color)
{
	wattron(border, COLOR_PAIR(233 + color));
	mvwprintw(border, 0, 0, "%s", str);
	wrefresh(border);
}

void			print_all(t_vm *vm, int time)
{
	int		color;

	color = vm->color;
	if (color < 0)
		color = -color;
	if ((vm->time_total + vm->time) % 5 == 0)
	{
		print_border(vm->border1, vm->line_border_y, color);
		print_border(vm->border2, vm->line_border_x, color);
		print_border(vm->border3, vm->line_border_y, color);
		print_border(vm->border4, vm->line_border_x, color);
		vm->color++;
		if (vm->color == 9)
			vm->color = -9;
	}
	print_map(vm);
	print_player(vm, vm->player_1, 1);
	if (vm->nbr_champ > 1)
		print_player(vm, vm->player_2, 2);
	if (vm->nbr_champ > 2)
		print_player(vm, vm->player_3, 3);
	if (vm->nbr_champ > 3)
		print_player(vm, vm->player_4, 4);
	print_stats(vm, vm->stats, time);
}

void			ft_print_visu(t_vm *vm)
{
	int		j;
	int		c;

	j = 1;
	print_all(vm, vm->speed);
	c = getch();
	if (c == 27)
		esc_visu(vm, 0);
	else if (c == '-' || c == '+')
	{
		if (c == '+' && vm->speed > 1)
			vm->speed -= 1000000;
		else if (c == '-' && vm->speed < 19000001)
			vm->speed += 1000000;
		mvprintw(65, 204, "Vitesse : %02d/20", 20 - (vm->speed / 1000000));
	}
	else if (c == 32 || c == '=')
		visu_pause(vm);
	j = 1;
	while (j < vm->speed)
		j++;
}
