/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_winer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:50:17 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/21 03:40:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	put_winer(t_champ *winer)
{
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/id champion [%d] %-25s \\\n", -winer->num, winer->name);
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/ %-42s \\\n", winer->comment);
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
}

static void	put_message(void)
{
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
	ft_printf("/ %-42s \\\n", "no champion has made live !!!!");
	ft_printf("{green}/ ****************************************** \\\n{eoc}");
}

void		ft_put_winer(t_vm *vm)
{
	t_champ *pt_champ;
	t_champ *winer;

	winer = NULL;
	pt_champ = vm->champs;
	esc_visu(vm);
	ft_put_mem(vm->mem);
	while (pt_champ)
	{
		if (pt_champ->num == vm->id_last_a_live)
			winer = pt_champ;
		pt_champ = pt_champ->next;
	}
	if (winer)
		put_winer(winer);
	else
		put_message();
	exit(0);
}
