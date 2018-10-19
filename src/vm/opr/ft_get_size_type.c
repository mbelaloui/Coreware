/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:13:19 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 10:14:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_size_type(int id_opr, int arg, t_op *op_tab[NBR_OP])
{
	if (arg == REG_CODE)
		return (REG_SIZE);
	else if (arg == IND_CODE)
		return (IND_SIZE);
	else if (arg == DIR_CODE)
		return (op_tab[id_opr]->size_label);
	return (0);
}
