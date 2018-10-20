/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_list_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:15:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 10:15:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void		ft_dell_list_process(t_process *list_process)
{
	t_process *pt;

	while (list_process)
	{
		pt = list_process;
		list_process = (list_process)->next;
		free(pt);
	}
}
