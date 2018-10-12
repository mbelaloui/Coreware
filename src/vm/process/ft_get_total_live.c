/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_total_live.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 11:31:52 by mint              #+#    #+#             */
/*   Updated: 2018/10/12 11:33:51 by mint             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_total_live(t_process *list_process)
{
	int total_live;

	total_live = 0;
	while (list_process)
	{
		total_live += list_process->nbr_live;
		list_process = list_process->next;
	}
	return (total_live);
}