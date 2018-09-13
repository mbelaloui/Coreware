/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:38:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 14:39:35 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_error_option(int id_error, char *name, t_option *op, char c)
{
	ft_printf("{red}Error{eoc} parameters arguments : unknown argument [%c].\n",
			c);
	ft_put_usage(name, op);
	exit(id_error);
}
