/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:16:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 14:58:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_vm_size(int fd)
{
	unsigned char	oct[4];
	int				size;

	size = 0;
	if (!ft_get_next_oct(fd, &oct))
		ft_error_reading_file(ERROR_READING_FILE);
	size = ft_byts_to_int(oct);
	if (size > CHAMP_MAX_SIZE)
		ft_error_reading_file(ERROR_SIZE_FILE);
	return (size);
}
