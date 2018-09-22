/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:15:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 18:17:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static int		manage_nbr_shift(intmax_t nbr, t_format *frmt, int shift)
{
	char	c;
	int		pt;

	pt = ((frmt->flags.plus) || nbr < 0) ? 1 : 0;
	c = (frmt->flags.zero) ? '0' : ' ';
	if ((frmt->min_length == 1 && frmt->precision == 0 && nbr == 0
				&& !frmt->flags.plus) || (frmt->flags.space && nbr >= 0))
	{
		ft_put_buf(' ', PUT_CHAR);
		pt++;
		shift--;
	}
	while (!frmt->flags.dash && shift > 0)
	{
		ft_put_buf(c, PUT_CHAR);
		shift--;
		pt++;
	}
	if (frmt->precision == 0 && nbr == 0 && frmt->min_length > 1
			&& !frmt->flags.plus)
		ft_put_buf(' ', PUT_CHAR);
	return (pt);
}

static void		put_generated_ret(t_format *format, intmax_t nbr, int size_ret,
		int shift)
{
	int		index_ret;

	index_ret = manage_nbr_shift(nbr, format, shift);
	index_ret += ft_put_nbr(nbr, format);
	while (index_ret + (int)format->len_temp < size_ret)
	{
		ft_put_buf(' ', PUT_CHAR);
		index_ret++;
	}
}

void			ft_generat_nbr_ret(intmax_t nbr, t_format *format)
{
	int size_ret;
	int shift;

	size_ret = ft_max(format->len_temp, format->precision);
	size_ret = ft_max(size_ret, format->min_length);
	shift = (size_ret - ft_max(format->len_temp, format->precision));
	if ((format->flags.plus || nbr < 0))
		shift--;
	if (nbr == 0 && format->precision == 0 && format->flags.plus
			&& format->min_length > 1 && !format->flags.dash)
		ft_put_buf(' ', PUT_CHAR);
	if (nbr == 0 && format->precision == 0 && format->flags.plus
			&& format->min_length > 1 && format->flags.dash)
		size_ret++;
	put_generated_ret(format, nbr, size_ret, shift);
}

void			ft_convert_nbr(t_format *format, va_list *ap)
{
	intmax_t	nbr;

	if (format->flags.dash || format->is_there_precision)
		format->flags.zero = 0;
	nbr = ft_get_convertion_size(va_arg(*ap, intmax_t), format->convertion);
	format->len_temp = (nbr == 0) ? 1 : ft_nbrlen(nbr);
	if (!format->is_there_precision && format->flags.zero)
		format->precision = format->min_length - 1;
	if (format->precision <= 0 && !format->is_there_precision)
		format->precision = 1;
	ft_generat_nbr_ret(nbr, format);
}
