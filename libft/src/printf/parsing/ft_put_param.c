/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:02:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:37:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static void		check_flags(char *str, t_format *format, int pt_end_of_format)
{
	int pt;

	pt = 0;
	while (pt < pt_end_of_format)
	{
		if (str[pt] == '#')
			format->flags.hashtag = 1;
		else if (str[pt] == '+')
			format->flags.plus = 1;
		else if (str[pt] == '-')
			format->flags.dash = 1;
		else if (str[pt] == ' ')
			format->flags.space = 1;
		else if (str[pt] == '0' && !ft_isdigit(str[pt - 1])
				&& str[pt - 1] != '.')
			format->flags.zero = 1;
		else if (str[pt] == '\'')
			format->flags.apo = 1;
		pt++;
	}
}

static void		get_convertion(char *str, t_convert *convertion,
		int pt_end_of_format)
{
	int pt;

	pt = 0;
	while (pt < pt_end_of_format)
	{
		if (str[pt] == 'l')
		{
			convertion->l = 1;
			convertion->nbr_l++;
		}
		if (str[pt] == 'h')
		{
			convertion->h = 1;
			convertion->nbr_h++;
		}
		if (str[pt] == 'j')
			convertion->j = 1;
		if (str[pt] == 'z')
			convertion->z = 1;
		pt++;
	}
}

static int		get_precision(char *str, int pt, t_format *format)
{
	pt++;
	format->is_there_precision = 1;
	if (ft_isdigit(str[pt]) || str[pt] == '*')
		format->precision = (str[pt] == '*') ? -2 : ft_atoi(str + pt);
	else
		format->precision = 0;
	if (str[pt] == '*')
		pt++;
	else
		pt += ft_nbrlen(format->min_length) + 2;
	return (pt);
}

static void		get_info(char *str, t_format *format, int pt_end_of_format,
		va_list *ap)
{
	int pt;

	pt = 0;
	while (pt < pt_end_of_format)
	{
		if (str[pt] == '0')
			pt++;
		else if (str[pt] == '.')
			pt = get_precision(str, pt, format);
		else if (str[pt - 1] != '.' && (ft_isdigit(str[pt]) || str[pt] == '*'))
		{
			format->is_there_min_length = 1;
			pt = ft_get_min_len(str, pt, format, ap);
		}
		else
			pt++;
	}
}

int				ft_put_param(va_list *ap, char *str, t_format *format)
{
	int			pt_end_of_format;

	if ((pt_end_of_format = ft_get_parssing_format(str, format)) == -1)
		return (-1);
	check_flags(str + 1, format, pt_end_of_format);
	get_info(str + 1, format, pt_end_of_format, ap);
	get_convertion(str + 1, &(format->convertion), pt_end_of_format);
	ft_switch_type(format, ap);
	return (pt_end_of_format + 1);
}
