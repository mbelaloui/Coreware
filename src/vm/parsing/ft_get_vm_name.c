/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:15:05 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 14:57:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

char	*ft_get_vm_name(int fd)
{
	unsigned char	oct[4];
	char			*name;
	char			*temp;
	int				byt;

	byt = 0;
	name = NULL;
	while (byt < (PROG_NAME_LENGTH / 4))
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
		{
			ft_printf("{red}Error reading file"
					"<name part> reaching unexpecting eof 2\n{eoc}");
			ft_printf("{red}Error while reading name Ko\n{eoc}");
			exit(0);
		}
		temp = ft_u_str_to_str(oct);
		name = ft_strjoin_clear(&name, &temp, BOTH);
		byt++;
	}
	return (name);
}
