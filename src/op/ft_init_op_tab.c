/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_op_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:29:06 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:59:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_init_op_tab(t_op *op_tab[NBR_OP])
{
	op_tab[0] = ft_new_op(0, "NULL", 0, 0);
	op_tab[1] = ft_new_op(1, "live", 1, 10);
	op_tab[2] = ft_new_op(2, "ld", 2, 5);
	op_tab[3] = ft_new_op(3, "st", 2, 5);
	op_tab[4] = ft_new_op(4, "add", 3, 10);
	op_tab[5] = ft_new_op(5, "sub", 3, 10);
	op_tab[6] = ft_new_op(6, "and", 3, 6);
	op_tab[7] = ft_new_op(7, "or", 3, 6);
	op_tab[8] = ft_new_op(8, "xor", 3, 6);
	op_tab[9] = ft_new_op(9, "zjmp", 1, 20);
	op_tab[10] = ft_new_op(10, "ldi", 3, 25);
	op_tab[11] = ft_new_op(11, "sti", 3, 25);
	op_tab[12] = ft_new_op(12, "fork", 1, 800);
	op_tab[13] = ft_new_op(13, "lld", 2, 10);
	op_tab[14] = ft_new_op(14, "lldi", 3, 50);
	op_tab[15] = ft_new_op(15, "lfork", 1, 1000);
	op_tab[16] = ft_new_op(16, "aff", 1, 2);
}
