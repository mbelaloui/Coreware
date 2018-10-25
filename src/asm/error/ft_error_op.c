/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:23:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/25 08:58:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_error_op(int error, char *str)
{
	if (error == ERROR_OP)
		ft_printf("{ref}Eror{eoc} instruction <%s> not found\n", str);
	else
		ft_printf("{ref}Eror{eoc} instruction not found\n");
	exit(error);
}
