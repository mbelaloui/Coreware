/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:25:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 19:49:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"
/*
void	put_desc_pt()
{

}

void	put_desc_actual_action()
{

}
*/

void	put_desc_process(int desc_mem)
{
	if (desc_mem == PLAYER_1 + ACTUAL_ACTION)
		ft_printf("{IGREEN}");
	else if (desc_mem == PLAYER_2 + ACTUAL_ACTION)
		ft_printf("{ired}");
	else if (desc_mem == PLAYER_3 + ACTUAL_ACTION)
		ft_printf("{icyan}");
	else// if (desc_mem == PLAYER_4 + ACTUAL_ACTION)
		ft_printf("{Iyellow}");
}

void	put_desc_player(int desc_mem)
{
	if (desc_mem == PLAYER_1)
		ft_printf("{green}");
	else if (desc_mem == PLAYER_2)
		ft_printf("{red}");
	else if (desc_mem == PLAYER_3)
		ft_printf("{cyan}");
	else if (desc_mem == PLAYER_4)
		ft_printf("{yellow}");
}

void	ft_put_mem(int mem[MEM_SIZE][2])
{
	int pt;

	pt = 0;
	while (pt < MEM_SIZE)
	{
		if ((pt % MEM_LINE == 0))
			ft_printf("\n");
		if (mem[pt][MEM_DESC] < 0)
			exit(-1);
		else if (mem[pt][MEM_DESC] == 0)
			ft_printf("{white}");
		else if (mem[pt][MEM_DESC] <= MAX_PLAYERS) //is player description
			put_desc_player(mem[pt][MEM_DESC]);
		else if (mem[pt][MEM_DESC] <= MAX_PLAYERS + ACTUAL_ACTION)
			put_desc_process(mem[pt][MEM_DESC]);
		else if (mem[pt][MEM_DESC] == PT_COLOR)
			ft_printf("{Iwhite}");
/*
		else if ((mem[pt][MEM_DESC] == PT_COLOR > MAX_PLAYERS)
		&& (mem[pt][MEM_DESC] == PT_COLOR < MAX_PLAYERS + COLOR_INVERS)) // is_actual player actin
			ft_printf("{white}");

		else if (mem[pt][MEM_DESC] == NULL_COLOR)
			ft_printf("{eoc}");
		else if (mem[pt][MEM_DESC] == NULL_COLOR)
			ft_printf("{blue}");
*/
		ft_printf("%.2x {eoc}", mem[pt][MEM_SRC]);
		pt++;
	}
	ft_printf("\n");
//	ft_temporize(2);
//	ft_clear_scr();
}
