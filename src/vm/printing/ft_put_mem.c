/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:25:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 10:30:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_mem(int mem[MEM_SIZE][2])
{
	int pt;

	pt = 0;
	while (pt < MEM_SIZE)
	{
		if ((pt % MEM_LINE == 0))
			ft_printf("\n");
		if (mem[pt][MEM_DESC] == PLAYER_1)
			ft_printf("{green}");
		if (mem[pt][MEM_DESC] == PLAYER_2)
			ft_printf("{red}");
		if (mem[pt][MEM_DESC] == PLAYER_3)
			ft_printf("{cyan}");
		if (mem[pt][MEM_DESC] == PLAYER_4)
			ft_printf("{yellow}");
		ft_printf("%.2x {eoc}", mem[pt][MEM_SEC]);
		pt++;
	}
}
