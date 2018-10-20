/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:34:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:35:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int	ft_get_size_param(t_op *op_tab[NBR_OP], int id_opr, unsigned char arg)
{
	if (arg == REG_CODE)
		return (REG_SIZE);
	else if (arg == DIR_CODE)
		return (op_tab[id_opr]->size_label);
	else if (arg == IND_CODE)
		return (IND_SIZE);
	else
		return (0);
}
