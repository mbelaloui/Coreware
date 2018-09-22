/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_value_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 10:14:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:37:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

int		ft_get_len_value_base(const intmax_t nbr, const int exit_base)
{
	int			len;
	intmax_t	temp_nbr;

	temp_nbr = nbr;
	len = 1;
	while (temp_nbr / exit_base)
	{
		temp_nbr = (temp_nbr / exit_base);
		len++;
	}
	return (len);
}
