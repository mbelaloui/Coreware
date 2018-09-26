/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_size_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:28:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 19:36:44 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_set_size_label(t_op *op_tab[NBR_OP])
{
	op_tab[0]->size_label = 0;
	op_tab[1]->size_label = 4;
	op_tab[2]->size_label = 4;
	op_tab[3]->size_label = 4;
	op_tab[4]->size_label = 4;
	op_tab[5]->size_label = 4;
	op_tab[6]->size_label = 4;
	op_tab[7]->size_label = 4;
	op_tab[8]->size_label = 4;
	op_tab[9]->size_label = 2;
	op_tab[10]->size_label = 2;
	op_tab[11]->size_label = 2;
	op_tab[12]->size_label = 2;
	op_tab[13]->size_label = 4;
	op_tab[14]->size_label = 2;
	op_tab[15]->size_label = 2;
	op_tab[16]->size_label = 4;
}
