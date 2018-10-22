/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switsh_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:37:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:37:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void	manage_priority_flag(t_format *format, va_list *ap)
{
	if (format->type == 'o' || format->type == 'u' || format->type == 'x')
		format->flags.plus = 0;
	if (format->type != 'c' && ft_is_convertion_type(format->type)
			&& ft_tolower(format->type) != 's' && format->type != 'd'
			&& format->type != 'i')
	{
		if (format->flags.dash || format->is_there_precision)
			format->flags.zero = 0;
	}
	if (format->flags.plus)
		format->flags.space = 0;
	if (format->min_length == -2)
		format->min_length = va_arg(*ap, int);
	if (format->precision == -2)
		format->precision = va_arg(*ap, int);
	if (format->min_length < 0)
		format->flags.dash = 1;
	format->min_length = (format->min_length < 0) ? -format->min_length
			: format->min_length;
	if (format->precision < 0)
		format->is_there_precision = 0;
}

static void	final_parsing(t_format *format)
{
	if ((ft_isupper(format->type) && format->type != 'X')
			|| format->type == 'p')
	{
		format->convertion.l = 1;
		format->convertion.nbr_l = 0;
	}
	if (format->type == 's' && format->convertion.l)
		format->type = 'S';
	if (format->type == 'c' && format->convertion.l)
		format->type = 'C';
	else if (format->type == 'O')
		format->type = 'o';
	else if (format->type == 'D')
		format->type = 'd';
	else if (format->type == 'U')
		format->type = 'u';
}

static void	get_len_printf(va_list *ap)
{
	intmax_t *len;

	len = va_arg(*ap, intmax_t*);
	*len = ft_put_buf(' ', LEN_BUF);
}

void		ft_switch_type(t_format *format, va_list *ap)
{
	final_parsing(format);
	manage_priority_flag(format, ap);
	if (format->type == 's')
		ft_convert_string(format, ap);
	else if (format->type == 'u')
		ft_convert_nbr_uns(format, ap);
	else if (format->type == 'd' || format->type == 'i')
		ft_convert_nbr(format, ap);
	else if (format->type == 'p')
		ft_convert_pointer(format, ap);
	else if (ft_tolower(format->type) == 'x' || format->type == 'b'
			|| format->type == 'o')
		ft_convert_nbr_base(format, ap);
	else if (format->type == 'c')
		ft_convert_char(format, ap);
	else if (format->type == 'S')
		ft_convert_wstring(format, ap);
	else if (format->type == 'C')
		ft_convert_wchar(format, ap);
	else if (format->type == 'n')
		get_len_printf(ap);
	else
		ft_generat_char_ret(format, format->type);
}
