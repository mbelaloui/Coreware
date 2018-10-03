/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 11:42:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:36:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void	put_min_pre(t_format *format)
{
	if (format->is_there_min_length)
	{
		ft_putstr(" -2- specified min lenght ->     ");
		ft_putnbr(format->min_length);
	}
	else
		ft_putstr(" -2- no specified min lenght");
	if (format->is_there_precision)
	{
		ft_putstr("\n -3- specified precision ->  ");
		ft_putnbr(format->precision);
	}
	else
		ft_putstr("\n -3- no specified precision <precision == 1>");
}

void		ft_put_format(t_format *format)
{
	if (format)
	{
		ft_putstr("format valide\n\t\tprint format : \n\n");
		ft_put_flags(&format->flags);
		put_min_pre(format);
		ft_putstr("\n -4- lenght of string -> ");
		ft_putnbr(format->len_temp);
		ft_putstr("\n ");
		ft_put_convertion(&format->convertion);
		ft_putstr("\n -6- specified type -> ");
		ft_putchar(format->type);
	}
	else
		ft_putstr("format is NULL");
	ft_putstr("\n");
}
