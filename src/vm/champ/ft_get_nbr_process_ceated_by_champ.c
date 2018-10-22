/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_process_ceated_by_champ.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:12:17 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 17:27:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_nbr_process_ceated_by_champ(t_process *list_process,
		int id_champ)
{
	int ret;

	ret = 0;
	while (list_process)
	{
		if (list_process->id_parent == id_champ)
			ret++;
		list_process = list_process->next;
	}
	return (ret);
}
