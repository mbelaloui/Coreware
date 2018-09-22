/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_signature.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:13:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 17:24:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_check_signature(unsigned char r[4])
{
	unsigned char	*ret;
	int				i;
	int				size;

	size = sizeof(int);
	ret = ft_int_to_byts(COREWAR_EXEC_MAGIC, size);
	i = 0;
	while (i < size)
	{
		if (r[i] != ret[i])
		{
			free(ret);
			return (F);
		}
		i++;
	}
	free(ret);
	return (T);
}
