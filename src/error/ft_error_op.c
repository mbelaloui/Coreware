/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:23:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:24:41 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_error_op(int error, char *str)
{
	if (error == ERROR_OP)
		ft_printf("{ref}Error{eoc} instruction <%s> not found\n", str);
	exit(error);
}
