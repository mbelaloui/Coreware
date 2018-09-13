/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:41:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:41:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void		ft_generat_ret(t_format *format, char *str, wchar_t val)
{
	int		shift;
	char	padd;
	int		nbr_char_put;

	shift = (format->flags.dash) ? 0 : format->min_length - format->len_temp;
	shift = (!val) ? 0 : shift;
	padd = (format->flags.zero) ? '0' : ' ';
	nbr_char_put = ft_fill_buf(shift, padd);
	if (!val)
	{
		ft_put_buf('\0', PUT_CHAR);
		nbr_char_put++;
	}
	else
		nbr_char_put += ft_put_str(str, format->len_temp);
	ft_fill_buf(format->min_length - nbr_char_put, ' ');
}

void			ft_convert_wchar(t_format *format, va_list *ap)
{
	wchar_t	val;
	char	str[5];

	val = (wchar_t)va_arg(*ap, wchar_t);
	ft_wchar_to_string(val, str);
	format->len_temp = ft_strlen(str);
	format->precision = format->len_temp;
	format->precision = (!val) ? 1 : format->precision;
	ft_generat_ret(format, str, val);
}
