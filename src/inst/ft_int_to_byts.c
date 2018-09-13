/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_byts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:47:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:53:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

unsigned int	*ft_int_to_byts(int val, int size)
{
	unsigned int *ret;

	if (!(ret = malloc(sizeof(int) * size)))
		return (NULL);
	if (size == DIR_SIZE)
	{
		ret[3] = (((unsigned int)val) << 24) >> 24;
		ret[2] = (((unsigned int)val) << 16) >> 24;
		ret[1] = (((unsigned int)val) << 8) >> 24;
		ret[0] = ((unsigned int)val) >> 24;
	}
	else if (size == IND_SIZE)
	{
		ret[1] = ((unsigned int)val << 24) >> 24;
		ret[0] = (((unsigned int)val) << 16) >> 24;
	}
	else if (size == REG_SIZE)
		ret[0] = ((unsigned int)val);
	else
		ret = NULL;
	return (ret);
}
