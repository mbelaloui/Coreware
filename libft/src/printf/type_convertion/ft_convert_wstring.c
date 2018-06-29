/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_wstring.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:43:06 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/29 11:50:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void		generat_wstring(t_format *format, wchar_t *wstr,
		int char_putted)
{
	int		pt;
	char	str[5];
	int		len_str;
	int		max_print;

	max_print = ft_max(format->min_length, format->precision);
	pt = 0;
	while (wstr[pt])
	{
		ft_wchar_to_string(wstr[pt], str);
		len_str = ft_wcharlen(wstr[pt]);
		if (char_putted + len_str <= max_print)
		{
			char_putted += len_str;
			ft_put_str(str, len_str);
		}
		else
			break ;
		pt++;
	}
	ft_fill_buf(format->min_length - char_putted, ' ');
}

static int		manage_shift(wchar_t *wstr, t_format *format)
{
	int		print;
	int		len_str;
	int		pt;
	int		max_print;

	max_print = ft_max(format->precision, format->min_length);
	print = 0;
	pt = 0;
	while (pt < (int)format->len_temp)
	{
		len_str = ft_wcharlen(wstr[pt]);
		if (print + len_str <= format->precision)
			print += len_str;
		else
			break ;
		pt++;
	}
	if (format->precision > format->min_length)
		max_print = print;
	return ((format->flags.dash) ? 0 : max_print - print);
}

void			ft_convert_wstring(t_format *format, va_list *ap)
{
	int		shift;
	char	padd;
	wchar_t	*wstr;
	int		nbr_char_put;

	wstr = (wchar_t *)va_arg(*ap, wchar_t*);
	if (wstr == NULL)
		wstr = L"(null)";
	format->len_temp = ft_wstringlen(wstr);
	if (!format->is_there_precision
			|| ((int)format->len_temp < format->precision))
		format->precision = format->len_temp;
	shift = manage_shift(wstr, format);
	padd = (format->flags.zero) ? '0' : ' ';
	shift = (shift < 0) ? -shift : shift;
	nbr_char_put = ft_fill_buf(shift, padd);
	generat_wstring(format, wstr, nbr_char_put);
}
