/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_desc_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:32:14 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 16:36:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_set_desc_param(t_op *op_tab[NBR_OP])
{
	op_tab[1]->desc_param = F;
	op_tab[2]->desc_param = T;
	op_tab[3]->desc_param = T;
	op_tab[4]->desc_param = T;
	op_tab[5]->desc_param = T;
	op_tab[6]->desc_param = T;
	op_tab[7]->desc_param = T;
	op_tab[8]->desc_param = T;
	op_tab[9]->desc_param = F;
	op_tab[10]->desc_param = T;
	op_tab[11]->desc_param = T;
	op_tab[12]->desc_param = F;
	op_tab[13]->desc_param = T;
	op_tab[14]->desc_param = T;
	op_tab[15]->desc_param = T;
	op_tab[16]->desc_param = T;
}
