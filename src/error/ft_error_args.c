/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:27:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:12:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_error_args(int error, char *op, char *args, char *arg)
{
	if (error == ERROR_ARG_NULL)
		ft_printf("{red}Error{eoc} no args found : [%s %s]\n",
				op, args);
	else if (error == ERROR_NBR_ARG)
		ft_printf("{red}Error{eoc} nbr args in instruction [%s %s]\n",
				op, args);
	else if (error == ERROR_FORMAT_ARG)
		ft_printf("{red}Error{eoc} format args in instruction"
				" [%s %s]\n", op, args);
	else if (error == ERROR_TYPE_ARG)
		ft_printf("{red}Error{eoc} type args [%s] in instruction"
				" [%s %s]\n", arg, op, args);
	else
		ft_printf("{red}Error{eoc} args [%s %s]\n", op, args);
	exit(error);
}
