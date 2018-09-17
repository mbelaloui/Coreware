/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_magic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:13:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 14:56:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** option bonus afficher plus de details
*/

void	ft_get_vm_magic(int fd)
{
	unsigned char oct[4];

	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
				"<probleme signature> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
	if (!ft_check_signature(oct))
	{
		ft_printf("{red}signature Ko\n{eoc}");
		exit(0);
	}
	else
		ft_printf("signature {green}ok\n{eoc}");
}
