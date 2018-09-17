/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:22:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 12:23:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_is_null(int fd)
{
	unsigned char oct[4];
	int			val;

	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
				"<null format> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
	//ft_put_oct(r);
	val = ft_byts_to_int(oct);
	if(val)
	{
		ft_printf("{red}Error fomrat programme"
				"<null programme>\n{eoc}");
		exit(0);
	}
	return (T);
}
