/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_bgn_champ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:39:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 14:42:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_bgn_champ(t_champ *champ, t_champ **list)
{
	t_champ		*pt_list;

	if (!list || !champ)
		return (F);
	if (!(*list))
		*list = champ;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = champ;
	}
	return (T);
}
