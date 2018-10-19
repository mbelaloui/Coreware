/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_optab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:09:53 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 15:00:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_free_optab(t_op *op_tab[NBR_OP])
{
	int i;

	i = 0;
	while (i < NBR_OP)
	{
		ft_strdel(&op_tab[i]->name);
		free(op_tab[i]);
		i++;
	}
}
