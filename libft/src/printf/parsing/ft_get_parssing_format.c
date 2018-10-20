/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parssing_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:16:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:37:00 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static int		is_flag(char c)
{
	char	*flag;
	int		pt;

	pt = 0;
	flag = "-+#0 hljz*.'$_q";
	while (flag[pt])
	{
		if (flag[pt] == c || ft_isdigit(c))
			return (1);
		pt++;
	}
	return (0);
}

int				ft_get_parssing_format(char *str, t_format *format)
{
	int cp;

	cp = 1;
	while (str[cp] && is_flag(str[cp]))
		cp++;
	if (str[cp] || ft_is_convertion_type(str[cp]))
	{
		format->type = str[cp];
		return (cp);
	}
	return (-1);
}
