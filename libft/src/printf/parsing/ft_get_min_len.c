/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:03:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:02:23 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static int	get_min_len_s(char *str, int pt, t_format *format)
{
	if (str[pt] == '*')
	{
		format->min_length = -2;
		pt++;
	}
	return (pt);
}

static int	get_min_len_n(char *str, int pt, t_format *format, va_list *ap)
{
	if (format->min_length == -2
			&& format->is_there_min_length && ft_isdigit(str[pt]))
		va_arg(*ap, int);
	if (ft_isdigit(str[pt]))
	{
		format->min_length = ft_atoi(str + pt);
		pt += ft_nbrlen(format->min_length);
	}
	return (pt);
}

int			ft_get_min_len(char *str, int pt, t_format *format, va_list *ap)
{
	pt = get_min_len_s(str, pt, format);
	pt = get_min_len_n(str, pt, format, ap);
	return (pt);
}
