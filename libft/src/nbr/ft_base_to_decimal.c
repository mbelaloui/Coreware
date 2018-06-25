/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:17:21 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/10 21:54:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

intmax_t				ft_base_to_decimal(const char *str, const int str_base)
{
	int			pt;
	intmax_t	nbr_ret;
	char		*temp;

	if ((str_base <= 1 || str_base > 16) || (str == NULL) ||
			(str[0] == '-') || str[0] == '+')
		return (0);
	nbr_ret = 0;
	pt = -1;
	temp = (char *)str;
	while (temp[++pt])
	{
		if (ft_isupper(temp[pt]))
			temp[pt] = ft_tolower(temp[pt]);
		if (!ft_is_elem_base(temp[pt], str_base))
			return (nbr_ret);
		nbr_ret = (nbr_ret * str_base) + ft_get_char_base(temp[pt]);
	}
	return (nbr_ret);
}
