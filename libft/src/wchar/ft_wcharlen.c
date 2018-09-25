/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:05:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 15:16:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wchar.h"

size_t		ft_wcharlen(wchar_t wc)
{
	if (wc > 0xFFFF)
		return (4);
	else if (wc > 0x7FF)
		return (3);
	else if (wc > 0x7F)
		return (2);
	return (1);
}
