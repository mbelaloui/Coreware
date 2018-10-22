/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:32:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/04 12:03:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

static	void	ecrire_nb_fd(intmax_t nbr, int fd)
{
	char	r;
	int		q;

	q = nbr / 10;
	r = (nbr % 10) + 48;
	if (q > 0)
	{
		ecrire_nb_fd(q, fd);
		ft_putchar_fd(r, fd);
	}
	else
		ft_putchar_fd(r, fd);
}

void			ft_putnbr_fd(intmax_t nbr, int fd)
{
	if (nbr >= 0)
		ecrire_nb_fd(nbr, fd);
	else
	{
		ft_putchar_fd('-', fd);
		if (nbr < MIN_INTMAX)
			ft_putstr_fd("9223372036854775808", fd);
		else
		{
			nbr = -nbr;
			ecrire_nb_fd(nbr, fd);
		}
	}
}
