/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_name_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:23:05 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 17:27:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

int		ft_is_name_op(char *str)
{
	t_op	*op_tab[NBR_OP];
	int		i;

	i = 0;
	ft_init_op_tab(op_tab);
	while (i < NBR_OP)
	{
		if (!ft_strcmp(op_tab[i]->name, str))
		{
			ft_dell_op(op_tab);
			return (i);
		}
		i++;
	}
	ft_dell_op(op_tab);
	return (-1);
}
