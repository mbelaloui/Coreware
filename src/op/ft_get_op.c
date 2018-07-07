/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:39:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 19:49:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

t_op	*ft_get_op(t_op *op_tab[NBR_OP], char *str)
{
	int i;

	i = 0;
	while (i < NBR_OP)
	{
		if (!ft_strcmp(op_tab[i]->name, str))
			return (op_tab[i]);
		i++;
	}
	return (NULL);
}
