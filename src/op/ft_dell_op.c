/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 20:20:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/25 08:48:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

static	BOOL	free_op(t_op *op_tab)
{
	if (!op_tab)
		return (F);
	ft_strdel(&op_tab->name);
	free(op_tab);
	return (T);
}

BOOL			ft_dell_op(t_op *op_tab[NBR_OP])
{
	int i;

	if (!op_tab)
		return (F);
	i = 0;
	while (i < NBR_OP)
	{
		if (!free_op(op_tab[i]))
			return (F);
		i++;
	}
	return (T);
}
