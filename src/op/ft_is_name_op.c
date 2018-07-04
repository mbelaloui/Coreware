/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_name_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:23:05 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/04 18:29:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

int		ft_is_name_op(char *str)
{
	int i;
	t_op *op_tab[17];

	i = 0;
	ft_init_op_tab(op_tab);
	while (i < NBR_OP)
	{
		if (ft_strcmp(op_tab[i]->name, str))
		{
			// free op tables
			return (i);
		}
		i++;
	}
	// free op tables
	return (0);
}
