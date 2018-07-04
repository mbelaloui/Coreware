/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base_stat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 14:54:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/04 18:35:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

void			ft_udecimal_to_base_stat(char *tab_ret, const uintmax_t nbr,
		const int base, const int form)
{
	int			len_ret;
	char		*elem_base;
	int			size_nbr_ret;
	uintmax_t	nbr_temp;

	if (base <= 1 || base > 16)
		return ;
	nbr_temp = nbr;
	elem_base = (form == LOWER) ? "0123456789abcdef" : "0123456789ABCDEF";
	size_nbr_ret = ft_get_len_value_ubase(nbr, base);
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
