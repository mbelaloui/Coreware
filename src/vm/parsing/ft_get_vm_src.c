/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vm_src.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 18:35:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_vm_inst	*ft_get_vm_src(int fd, t_champ *champ, t_op *op_tab[NBR_OP])
{
	char		*src;
	t_vm_inst	*src_list;

//	ft_printf("\n id %d - name [%s]\n",champ->id, champ->name);


	src = ft_read_src(fd, champ->size);

//	ft_put_raw_src_champ(src, champ->size);

	src_list = ft_str_to_list_inst(src, champ, op_tab);

	ft_strdel(&src);
	
	return (src_list);
}
