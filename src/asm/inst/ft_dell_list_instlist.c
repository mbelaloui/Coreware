/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_list_instlist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:03:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 12:48:14 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

BOOL	ft_dell_list_instlist(t_instlist **to_free)
{
	t_instlist*pt;

	if (!to_free || !(*to_free))
		return (F);
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		*to_free = (*to_free)->next;
		ft_dell_inst(&(pt->data));
		free(pt);
	}
	*to_free = NULL;
	return (T);
}
