/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 12:23:06 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:35:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

void	ft_format_init(t_format *format)
{
	if (format)
	{
		format->flags.dash = 0;
		format->flags.apo = 0;
		format->flags.plus = 0;
		format->flags.hashtag = 0;
		format->flags.zero = 0;
		format->flags.space = 0;
		format->min_length = 0;
		format->is_there_min_length = 0;
		format->precision = 1;
		format->is_there_precision = 0;
		format->convertion.l = 0;
		format->convertion.h = 0;
		format->convertion.nbr_l = 0;
		format->convertion.nbr_h = 0;
		format->convertion.z = 0;
		format->convertion.j = 0;
		format->type = '!';
		format->len_temp = 0;
	}
}
