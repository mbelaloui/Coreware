/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uconvertion_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:48:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:41:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static uintmax_t		get_h(intmax_t data, t_convert conv)
{
	if (conv.nbr_h % 2)
		return ((unsigned short)data);
	else
		return ((unsigned char)data);
}

static uintmax_t		get_l(intmax_t data, t_convert conv)
{
	if (conv.nbr_l % 2)
		return ((unsigned long)data);
	else
		return ((unsigned long long)data);
}

uintmax_t				ft_get_uconvertion_size(uintmax_t data, t_convert conv)
{
	if (conv.l)
		return (get_l(data, conv));
	if (conv.j)
		return (data);
	if (conv.z)
		return ((size_t)data);
	if (conv.h)
		return (get_h(data, conv));
	return ((unsigned)data);
}
