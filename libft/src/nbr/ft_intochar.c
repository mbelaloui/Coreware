/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intochar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:28:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:45:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

char		ft_intochar(const int nbr)
{
	if (ft_isprint(nbr + '0'))
		return (nbr + '0');
	return (0);
}
