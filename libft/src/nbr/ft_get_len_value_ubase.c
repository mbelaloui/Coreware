/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_value_ubase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:38:37 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:38:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

int		ft_get_len_value_ubase(const uintmax_t nbr, const int exit_base)
{
	int			len;
	uintmax_t	temp_nbr;

	temp_nbr = nbr;
	len = 1;
	while (temp_nbr / exit_base)
	{
		temp_nbr = (temp_nbr / exit_base);
		len++;
	}
	return (len);
}
