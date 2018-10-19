/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:09:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 15:00:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_get_op_tab(t_op *op_tab[NBR_OP])
{
	ft_init_op_tab(op_tab);
	ft_set_param(op_tab);
	ft_set_desc_param(op_tab);
	ft_set_size_label(op_tab);
}
