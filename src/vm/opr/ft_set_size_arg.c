/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_size_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:19:45 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 16:10:06 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int	ft_set_size_arg(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP])
{
	int pt;
	int size;

	size = 0;
	pt = 0;
	while (pt < opr_exe->nbr_param)
	{
		opr_exe->size_arg[pt] = ft_get_size_type(opr_exe->id_opr,
			opr_exe->type_arg[pt][type_2], op_tab);
		size += opr_exe->size_arg[pt];
		pt++;
	}
	return (size);
}
