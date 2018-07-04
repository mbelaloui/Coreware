/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 20:20:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/04 21:26:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

static	BOOL	free_op(t_op *op_tab)
{
	if (!op_tab)
		return (F);
	ft_strdell(op_tab->name);
	return (T);
}

BOOL			ft_dell_op(t_op *op_tab[NBR_OP])
{
	int i;

	if (!op_tab)
		return (F);
	i = 0;
	while (op_tab[i])
	{
		if (!free_op(op_tab[i]))
			return (F);
		i++;
	}
	return (T);
}
