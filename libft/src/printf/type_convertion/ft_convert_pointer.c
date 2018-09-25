/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:07:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:40:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void		put_base(t_format *format, int shift, int size_ret, char *str)
{
	int nbr_char_put;

	nbr_char_put = 0;
	if (!format->flags.zero)
		nbr_char_put = ft_fill_buf(shift, ' ');
	ft_put_buf('0', PUT_CHAR);
	ft_put_buf('x', PUT_CHAR);
	if (format->flags.zero)
		nbr_char_put = ft_fill_buf(shift, '0');
	if (format->precision > (int)format->len_temp || shift > 0)
		nbr_char_put += ft_fill_buf(format->precision - format->len_temp, '0');
	nbr_char_put += ft_put_str(str, format->len_temp);
	ft_fill_buf(size_ret - nbr_char_put, ' ');
}

static void		generat_base_ret(t_format *format, char *str)
{
	int		shift;
	int		size_ret;

	size_ret = ft_max(format->len_temp, format->precision);
	size_ret = ft_max(size_ret, format->min_length);
	shift = size_ret - ft_max(format->len_temp, format->precision);
	shift = (format->flags.dash) ? 0 : shift;
	shift -= 2;
	size_ret -= 2;
	put_base(format, shift, size_ret, str);
}

void			ft_convert_pointer(t_format *format, va_list *ap)
{
	uintmax_t	nbr;
	char		temp_tab[SIZE_TAB_CONV * 2];

	ft_memset(temp_tab, ' ', sizeof(temp_tab) - 1);
	nbr = va_arg(*ap, uintmax_t);
	if (nbr != 0)
	{
		nbr = ft_get_uconvertion_size(nbr, format->convertion);
		ft_udecimal_to_base_stat(temp_tab, nbr, EXA, LOWER);
	}
	else
		temp_tab[0] = '\0';
	format->len_temp = ft_strlen(temp_tab);
	if (!format->is_there_precision)
		format->precision = format->len_temp;
	if (format->precision <= 0 && !format->is_there_precision)
		format->precision = 1;
	generat_base_ret(format, temp_tab);
}
