/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:18:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 10:23:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static int	get_add_start_process(int nbr_champ, int pos)
{
	if (pos == 0)
		return (0);
	else if (nbr_champ == 2)
		return (MEM_SIZE / 2);
	else if (nbr_champ == 3)
		return (MEM_SIZE / 3);
	else if (nbr_champ == 4)
		return (MEM_SIZE / 4);
	return (0);
}

static void	set_sart_add(t_process *list, int nbr_champ)
{
	int add_start;
	int id_champ;

	id_champ = 0;
	add_start = 0;
	while (list)
	{
		add_start += get_add_start_process(nbr_champ, id_champ++);
		list->pc = add_start;
		list = list->next;
	}
}

t_process	*ft_init_process(t_vm vm)
{
	t_process	*list_ret;
	t_champ		*champ;

	champ = vm.champs;
	list_ret = NULL;
	while (champ)
	{
		ft_add_process(ft_new_process(champ->id, 0), &list_ret);
		champ = champ->next;
	}
	set_sart_add(list_ret, vm.nbr_champ);
	return (list_ret);
}
