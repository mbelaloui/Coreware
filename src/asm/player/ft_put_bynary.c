/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bynary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:22:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 17:21:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_put_bynary(int data, int size, int fd)
{
	unsigned char *ret;

	ret = ft_int_to_byts(data, size);
	if (size == REG_SIZE)
	{
		write(fd, &ret[0], 1);
	}
	else if (size == IND_SIZE)
	{
		write(fd, &ret[0], 1);
		write(fd, &ret[1], 1);
	}
	else if (size == DIR_SIZE)
	{
		write(fd, &ret[0], 1);
		write(fd, &ret[1], 1);
		write(fd, &ret[2], 1);
		write(fd, &ret[3], 1);
	}
	free(ret);
}
