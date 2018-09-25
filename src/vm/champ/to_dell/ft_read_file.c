/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:04:21 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 18:15:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_champ		*ft_read_file(int fd, t_op*op_tab[NBR_OP])
{
	t_champ	*champ;

	ft_get_vm_magic(fd);  // ajouter le teste pour fichier vide
	if (!(champ = malloc(sizeof(*champ))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	champ->name = ft_get_vm_name(fd);
	if (ft_is_null(fd))
	{
		champ->size = ft_get_vm_size(fd);
		champ->comment = ft_get_vm_comment(fd);
		if (ft_is_null(fd))
			ft_get_vm_src(fd, champ, op_tab);
		else
			ft_error_reading_file(ERROR_FORMAT_FILE);
	}
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);
//	ft_dell_champ(&champ);
	return (champ);
}
