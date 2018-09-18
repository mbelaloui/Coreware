/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byts_to_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:04:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 12:08:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

int		ft_byts_to_int(unsigned char b[4])
{
	return ((((((b[0] << 8) | b[1]) << 8) | b[2]) << 8) | b[3]);
}