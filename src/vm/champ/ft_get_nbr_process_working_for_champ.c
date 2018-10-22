/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_process_working_for_champ.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:13:14 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 15:13:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_nbr_process_working_for_champ(t_process *list_process,
		int id_champ)
{
	int ret;

	ret = 0;
	while (list_process)
	{
		if (list_process->reg[0] == id_champ)
			ret++;
		list_process = list_process->next;
	}
	return (ret);
}