/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_need_desc_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:46:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:59:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_need_desc_op(char *name_op, t_op *op_tab[NBR_OP])
{
	t_op *op;

	op = ft_get_op(op_tab, name_op);
	return (op->desc_param);
}
