/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end_champ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:41:17 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 14:44:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_end_champ(t_champ *champ, t_champ **list)
{
//	t_int_list *temp_node;

	if (!champ || !list)
		return (F);
	if (!(*list))
		*list = champ;
	else
	{
		champ->next = *list;
		*list = champ;
	}
	return (T);
}