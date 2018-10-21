/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:19:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 10:23:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL		ft_add_process(t_process *proces, t_process **list)
{
	if (!proces || !list)
		return (F);
	if (!(*list))
		*list = proces;
	else
	{
		proces->next = *list;
		*list = proces;
	}
	return (T);
}
