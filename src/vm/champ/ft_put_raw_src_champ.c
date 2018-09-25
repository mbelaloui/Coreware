/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_raw_src_champ.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:44:42 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 12:45:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_raw_src_champ(char *src, int size)
{
	int i;

	i = 0;
	ft_printf("\n\t\t printing raw src", src[i]);
	ft_printf("\n\t/ ***************************** \\ \n\n", src[i]);
	while(i < size)
	{
		ft_printf("%.2x ", (unsigned char)src[i]);
		i++;
		if (i % 8 == 0)
			ft_printf("  ");
		if (i % 16 == 0)
			ft_printf("\n");
	}
	ft_printf("\n\n\t/ ***************************** \\ \n\n", src[i]);
}
