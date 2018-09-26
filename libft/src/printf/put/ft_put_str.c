/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:04:22 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:38:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/printf.h"

int		ft_put_str(char *print, intmax_t max_print)
{
	int pt;

	pt = 0;
	while (pt < max_print)
	{
		ft_put_buf(print[pt], PUT_CHAR);
		pt++;
	}
	return (pt);
}
