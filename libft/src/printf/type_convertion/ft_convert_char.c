/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:58:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:39:09 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

void	ft_generat_char_ret(t_format *format, unsigned char temp)
{
	int		shift;
	int		pt_temp;

	shift = (format->flags.dash) ? 0 : format->min_length - 1;
	pt_temp = shift;
	ft_fill_buf(shift, (format->flags.zero) ? '0' : ' ');
	while (pt_temp < shift + 1)
	{
		ft_put_buf(temp, PUT_CHAR);
		pt_temp++;
	}
	ft_fill_buf(format->min_length - pt_temp, ' ');
}

void	ft_convert_char(t_format *format, va_list *ap)
{
	long	temp;

	temp = (int)va_arg(*ap, int);
	if (format->convertion.l && format->convertion.nbr_l % 2 == 1)
	{
		if (temp >= 0 && temp <= 255)
			ft_generat_char_ret(format, temp);
	}
	else
		ft_generat_char_ret(format, (unsigned char)temp);
}
