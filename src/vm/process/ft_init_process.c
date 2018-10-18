/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:18:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 10:34:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static int	get_add_start_process(int nbr_champ, int pos)
{
	if (pos == 1)
		return (0);
	else if (nbr_champ == 2)
		return (MEM_SIZE / 2);
	else if (nbr_champ == 3)
		return (MEM_SIZE / 3);
	else if (nbr_champ == 4)
		return (MEM_SIZE / 4);
	return (0);
}

/*
**	ft_printf(" champ num = %d   position %d \n", champ->num, champ->id);
*/

t_process	*ft_init_process(t_vm vm)
{
	t_process	*list_ret;
	t_champ		*champ;
	int			add_start;

	champ = vm.champs;
	list_ret = NULL;
	add_start = 0;
	while (champ)
	{
		add_start += get_add_start_process(vm.nbr_champ, champ->pos);
		ft_add_process(ft_new_process(champ->num, add_start, champ->pos)
		, &list_ret);
		champ = champ->next;
	}
	return (list_ret);
}
