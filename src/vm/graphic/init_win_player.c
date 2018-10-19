/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 19:49:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 19:50:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

WINDOW		*init_win_player(WINDOW *player, int num, int color)
{
	char	str[WIN_PLAYER_X * WIN_PLAYER_Y];
	int		i;
	int		j;

	i = 0;
	j = 25 + ((WIN_PLAYER_Y + 1) * (num - 10));
	init_pair(num, color, COLOR_GREY_LIGHT);
	player = newwin(WIN_PLAYER_Y, WIN_PLAYER_X, j, 200);
	while (i <= WIN_PLAYER_X * WIN_PLAYER_Y)
		str[i++] = ' ';
	wattrset(player, COLOR_PAIR(num));
	wprintw(player, "%s", str);
	wrefresh(player);
	return (player);
}
