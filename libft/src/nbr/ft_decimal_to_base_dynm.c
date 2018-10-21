/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base_dynm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:55:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:56:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

static char		*get_result(intmax_t nbr, int base, char *elem_base, int size)
{
	char *result;

	result = ft_strnew(size);
	while (size--)
	{
		result[size] = ft_gettab_val(elem_base, nbr % base);
		nbr = nbr / base;
	}
	return (result);
}

char			*ft_decimal_to_base_dynm(const intmax_t nbr_in, int base,
		int form)
{
	char		*ret;
	char		*elem_base;
	int			size_nbr_ret;
	intmax_t	nbr;

	nbr = (nbr_in < 0) ? -nbr_in : nbr_in;
	if (base <= 1 || base > 16)
		return (0);
	elem_base = (form == LOWER) ? "0123456789abcdef" : "0123456789ABCDEF";
	size_nbr_ret = ft_get_len_value_base(nbr, base);
	ret = get_result(nbr, base, elem_base, size_nbr_ret);
	return (ret);
}
