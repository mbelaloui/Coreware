/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:27:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/25 08:59:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_error_args(int error, char *op, char *args, char *arg)
{
	ft_printf("{red}Error arguments{eoc} ");
	if (error == ERROR_ARG_NULL)
		ft_printf("No args found : [%s %s]\n",
				op, args);
	else if (error == ERROR_NBR_ARG)
		ft_printf("Nbr args in instruction [%s %s]\n",
				op, args);
	else if (error == ERROR_FORMAT_ARG)
		ft_printf("Bad format args in instruction"
				" [%s %s]\n", op, args);
	else if (error == ERROR_TYPE_ARG)
		ft_printf("Type args [%s] not reconized\n", arg);
	else
		ft_printf("Args [%s %s]\n", op, args);
	exit(error);
}
