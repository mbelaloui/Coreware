/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atointmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:24:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/06 14:00:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

intmax_t	ft_atointmax(const char *str)
{
	int signe;
	int pt;

	signe = (*str == '-') ? -1 : 1;
	pt = (*str == '-' || *str == '+') ? 1 : 0;
	return (signe * ft_base_to_decimal(str + pt, 10));
}
