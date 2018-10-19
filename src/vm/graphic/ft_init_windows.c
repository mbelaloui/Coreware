/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_windows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:47:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 19:54:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	init_visu()
{
	initscr();
	start_color();
	init_color(COLOR_WHITE, 999, 999, 999);
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
}

static WINDOW		*init_win_map(WINDOW *map)
{
	init_pair(COLOR_MAP, COLOR_GREY_LOW, COLOR_GREY_LESS);
	map = newwin(WIN_MAP_Y, WIN_MAP_X, 1, 2);
	wattrset(map, COLOR_PAIR(COLOR_MAP));
	wrefresh(map);
	return (map);
}

static WINDOW		*init_win_stats(WINDOW *stats)
{
	char	str[WIN_STATS_X * WIN_STATS_Y];
	int		i;

	i = 0;
	init_pair(COLOR_STATS, COLOR_BASIC, COLOR_GREY_LIGHT);
	stats = newwin(WIN_STATS_Y, WIN_STATS_X, 2, 200);
	while (i <= WIN_STATS_X * WIN_STATS_Y)
		str[i++] = ' ';
	wattrset(stats, COLOR_PAIR(COLOR_STATS));
	wprintw(stats, "%s", str);
	wrefresh(stats);
	return (stats);
}

static void		color_the_deep(void)
{
	int		y;
	int		x;
	char	*str;

	y = 0;
	x = 0;
	str = ft_strnew(COLS);
	while (x <= COLS)
		str[x++] = ' ';
	init_pair(COLOR_DEEP, COLOR_BASIC, COLOR_GREY_MEDIUM);
	attrset(COLOR_PAIR(COLOR_DEEP));
	while (y <= LINES)
	{
		printw("%s", str);
		y++;
	}
	mvprintw(64, 204, "Vitesse :\t20/20");
}

void	ft_init_windows(t_vm *vm)
{
	init_visu();
	color_the_deep();
	getch();
	vm->map = init_win_map(vm->map);
	vm->stats = init_win_stats(vm->stats);
	vm->player_1 = init_win_player(vm->player_1, PLAYER_1 + NULL_COLOR,
	COLOR_PLAYER_1);
	if (vm->nbr_champ > 1)
		vm->player_2 = init_win_player(vm->player_2, PLAYER_2 + NULL_COLOR,
		COLOR_PLAYER_2);
	if (vm->nbr_champ > 2)
		vm->player_3 = init_win_player(vm->player_3, PLAYER_3 + NULL_COLOR,
		COLOR_PLAYER_3);
	if (vm->nbr_champ > 3)
		vm->player_4 = init_win_player(vm->player_4, PLAYER_4 + NULL_COLOR,
		COLOR_PLAYER_4);
	ft_print_visu(vm);

//	ft_printf("adosndojasndoasnodia \n");
	endwin();
	exit(0);
}