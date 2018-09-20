/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_byts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:47:47 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 13:07:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

unsigned int	*ft_int_to_byts(int val, int size)
{
	unsigned int *ret;

	if (!(ret = malloc(sizeof(int) * size)))
		return (NULL);
	if (size == 4)
	{
		ret[3] = (((unsigned int)val) << 24) >> 24;
		ret[2] = (((unsigned int)val) << 16) >> 24;
		ret[1] = (((unsigned int)val) << 8) >> 24;
		ret[0] = ((unsigned int)val) >> 24;
	}
	else if (size == 2)
	{
		ret[1] = ((unsigned int)val << 24) >> 24;
		ret[0] = (((unsigned int)val) << 16) >> 24;
	}
	else if (size == 1)
		ret[0] = ((unsigned int)val);
	else
		ret = NULL;
	return (ret);
}
