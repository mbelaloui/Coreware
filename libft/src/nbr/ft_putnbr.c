/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:56:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:53:29 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

void		ft_putnbr(intmax_t nbr)
{
	if (nbr < 0)
	{
		ft_putstr("-");
		if (nbr < MIN_INTMAX)
			ft_putstr("9223372036854775808");
		else
			ft_putnbr(-nbr);
	}
	else
	{
		if (nbr / 10)
			ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
}
