/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:20:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:20:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_put_type_param(t_op *op_tab[17])
{
	int i;

	i = 0;
	ft_printf("Parameters type :\n\n");
	while (i < 17)
	{
		ft_printf("[%s]\n\tparam 1 [", ft_get_name(op_tab[i]));
		ft_put_op_param_1(op_tab[i]);
		ft_printf("]\n\tparam 2 [");
		ft_put_op_param_2(op_tab[i]);
		ft_printf("]\n\tparam 3 [");
		ft_put_op_param_3(op_tab[i]);
		ft_printf("]\n");
		i++;
	}
}
