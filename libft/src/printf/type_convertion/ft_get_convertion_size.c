/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_convertion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:06:12 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:41:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

static long		get_h(intmax_t data, t_convert conv)
{
	if (conv.nbr_h % 2)
		return ((short)data);
	else
		return ((char)data);
}

static long		get_l(intmax_t data, t_convert conv)
{
	if (conv.nbr_l % 2)
		return ((long)data);
	else
		return ((long long)data);
}

intmax_t		ft_get_convertion_size(intmax_t data, t_convert conv)
{
	if (conv.l)
		return (get_l(data, conv));
	if (conv.j)
		return (data);
	if (conv.z)
		return ((size_t)data);
	if (conv.h)
		return (get_h(data, conv));
	return ((int)data);
}
