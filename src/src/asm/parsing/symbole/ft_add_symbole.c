/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_symbole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:27:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 16:00:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

BOOL	ft_add_symbole(char *data, int add, t_symbole **list, t_option *op)
{
	t_symbole	*temp_node;
	t_symbole	*pt_list;

	if (!(temp_node = ft_new_symbole(data, add)))
		return (F);
	if (ft_is_in_symbole(data, *list) > -1)
		ft_warning(WARNING_DOUBLE_DEF_LAB, 0, data, op);
	if (!(*list))
		*list = temp_node;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp_node;
	}
	return (T);
}
