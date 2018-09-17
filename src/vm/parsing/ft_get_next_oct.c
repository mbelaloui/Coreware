/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_oct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:02:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 14:53:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_get_next_oct(int fd, unsigned char (*tab)[4])
{
	unsigned char	buf[1];
	int				size;
	int				i;

	i = 0;
	size = sizeof(int);
	while (i < size)
	{
		if (!read(fd, &buf, 1))
			return (F);
		(*tab)[i] = buf[0];
		i++;
	}
	return (T);
}
