/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:52:48 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:38:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void		put_nbr(uintmax_t nbr)
{
	if (nbr / 10)
		put_nbr(nbr / 10);
	ft_put_buf((nbr % 10) + '0', PUT_CHAR);
}

static int		put_zero(t_format *format)
{
	int		nbr_0;
	int		ret_nbr_put;

	nbr_0 = (format->precision - format->len_temp);
	nbr_0 = (nbr_0 > 0) ? nbr_0 : 0;
	ret_nbr_put = nbr_0;
	while (nbr_0)
	{
		ft_put_buf('0', PUT_CHAR);
		nbr_0--;
	}
	return (ret_nbr_put);
}

int				ft_put_unbr(uintmax_t nbr, t_format *format)
{
	int		pt;

	pt = put_zero(format);
	if (!(format->precision == 0 && nbr == 0))
		put_nbr(nbr);
	return (pt);
}
