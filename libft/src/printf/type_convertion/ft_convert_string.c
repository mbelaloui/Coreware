/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:58:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/16 19:17:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void		ft_generat_ret(t_format *format, char *str)
{
	int		shift;
	char	padd;
	int		nbr_char_put;
	int		max_print;
	int		size_ret;

	shift = (format->flags.dash) ? 0 : format->min_length - format->precision;
	padd = (format->flags.zero) ? '0' : ' ';
	nbr_char_put = ft_fill_buf(shift, padd);
	size_ret = ft_max(format->len_temp, format->min_length);
	max_print = ft_min(size_ret, format->precision);
	nbr_char_put += ft_put_str(str, max_print);
	ft_fill_buf(format->min_length - nbr_char_put, ' ');
}

void			ft_convert_string(t_format *format, va_list *ap)
{
	char	*str;

	str = (char *)va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	if (format->precision)
		format->len_temp = ft_strlen(str);
	else
		format->len_temp = 0;
	if (!format->is_there_precision ||
			((int)format->len_temp < format->precision))
		format->precision = format->len_temp;
	ft_generat_ret(format, str);
}
