/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base_stat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:54:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:56:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

void			ft_decimal_to_base_stat(char *tab_ret, const intmax_t nbr,
		const int base, const int form)
{
	int			len_ret;
	char		*elem_base;
	int			size_nbr_ret;
	intmax_t	nbr_temp;

	nbr_temp = (nbr < 0) ? -nbr : nbr;
	if (base <= 1 || base > 16)
		return ;
	elem_base = (form == LOWER) ? "0123456789abcdef" : "0123456789ABCDEF";
	size_nbr_ret = ft_get_len_value_base(nbr, base);
	len_ret = ft_strlen(tab_ret);
	if (!tab_ret || (len_ret < size_nbr_ret))
		return ;
	ft_memset(tab_ret, ' ', len_ret);
	tab_ret[size_nbr_ret] = '\0';
	while (size_nbr_ret--)
	{
		tab_ret[size_nbr_ret] = ft_gettab_val(elem_base, nbr_temp % base);
		nbr_temp = nbr_temp / base;
	}
}
