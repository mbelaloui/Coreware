/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_champ_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:31:08 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 09:15:08 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_champ		*ft_read_champ_file(int fd, int num, t_op *op_tab[NBR_OP], int pos)
{
	t_champ	*champ;

	ft_get_vm_magic(fd);
	champ = NULL;
	if (!(champ = ft_new_champ(num, pos)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
//	champ->num = num;
	champ->name = ft_get_vm_name(fd);
	if (ft_is_null(fd))
	{
		champ->size = ft_get_vm_size(fd);
		champ->comment = ft_get_vm_comment(fd);
		if (ft_is_null(fd))
			champ->src = ft_get_vm_src(fd, champ, op_tab);
		else
			ft_error_reading_file(ERROR_FORMAT_FILE);
	}
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);
	return (champ);
}
