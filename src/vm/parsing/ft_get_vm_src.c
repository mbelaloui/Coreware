/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:36:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_vm_inst	*ft_get_vm_src(int fd, t_champ *champ, t_op *op_tab[NBR_OP])
{
	char		*src;
	t_vm_inst	*src_list;

	src = ft_read_src(fd, champ->size);
	src_list = ft_str_to_list_inst(src, champ, op_tab);
	ft_strdel(&src);
	return (src_list);
}
