/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:20:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 11:20:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

BOOL	ft_is_type_ok(t_op *op_tab, int type)
{
	if (op_tab && type & ft_get_type_param(op_tab))
		return (T);
	return (F);
}
