/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:38:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:25:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf.h"

static void	run(char *str, va_list *ap)
{
	int			pt;
	t_format	format;

	while (*str)
	{
		pt = 0;
		ft_format_init(&format);
		while (*str && *str != '%' && *str != '{')
		{
			ft_put_buf(*str, PUT_CHAR);
			str++;
		}
		if (*str == '%')
			pt = ft_put_param(ap, str, &format);
		if (*str == '{')
			pt = ft_get_color(str);
		if (pt == -1)
			break ;
		str = str + pt;
	}
}

int			ft_printf(const char *input, ...)
{
	char	*str_format;
	int		len;
	va_list	ap;

	va_start(ap, input);
	str_format = (char *)input;
	if (!str_format)
	{
		write(1, "NULL", 4);
		return (-1);
	}
	run(str_format, &ap);
	len = ft_put_buf(' ', EOL);
	ft_put_buf(' ', RESET);
	va_end(ap);
	return (len);
}
