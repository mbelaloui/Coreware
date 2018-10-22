/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_list_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:14:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 15:14:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int				ft_get_size_list_process(const t_process *list_process)
{
	int ret;

	ret = 0;
	while (list_process)
	{
		ret++;
		list_process = list_process->next;
	}
	return (ret);
}