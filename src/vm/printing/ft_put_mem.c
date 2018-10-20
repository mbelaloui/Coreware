/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:25:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/20 15:23:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	put_desc_process(int desc_mem)
{
	if (desc_mem == REVERS_COLOR)
		ft_printf("{Iwhite}");
	else if (desc_mem == REVERS_COLOR + PLAYER_1)
		ft_printf("{Igreen}");
	else if (desc_mem == REVERS_COLOR + PLAYER_2)
		ft_printf("{ired}");
	else if (desc_mem == REVERS_COLOR + PLAYER_3)
		ft_printf("{icyan}");
	else if (desc_mem == REVERS_COLOR + PLAYER_4)
		ft_printf("{Iyellow}");
}

static void	put_desc_player(int desc_mem)
{
	if (desc_mem == NULL_COLOR)
		ft_printf("{white}");
	else if (desc_mem == NULL_COLOR + PLAYER_1)
		ft_printf("{green}");
	else if (desc_mem == NULL_COLOR + PLAYER_2)
		ft_printf("{red}");
	else if (desc_mem == NULL_COLOR + PLAYER_3)
		ft_printf("{cyan}");
	else if (desc_mem == NULL_COLOR + PLAYER_4)
		ft_printf("{yellow}");
}

void	ft_put_mem(int mem[MEM_SIZE][2])
{
	int pt;

	ft_clear_scr();
	pt = 0;
	while (pt < MEM_SIZE)
	{
		if ((pt % MEM_LINE == 0))
			ft_printf("\n");
/*		if (mem[pt][MEM_DESC] < 0) //c'est la que sa foire conardd de merde putin 
			exit(-1);*/
/*		else */
		if (mem[pt][MEM_DESC] <= NULL_COLOR + MAX_PLAYERS)
			put_desc_player(mem[pt][MEM_DESC]);
		else if (mem[pt][MEM_DESC] <= REVERS_COLOR + MAX_PLAYERS)
			put_desc_process(mem[pt][MEM_DESC]);
		ft_printf("%.2x {eoc}", mem[pt][MEM_SRC]);
		pt++;
	}
	ft_printf("\n");
}
