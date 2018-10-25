/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_list_inst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:33:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 18:33:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_vm_inst	*ft_str_to_list_inst(char *src, t_champ *champ,
		t_op *op_tab[NBR_OP])
{
	t_int_list		*inst_src_list;
	t_vm_inst		*vm_src;
	int				i;
	int				opr;
	t_op			*op;

	i = 0;
	vm_src = NULL;
	while (i < champ->size)
	{
		inst_src_list = NULL;
		opr = src[i];
		i += ft_manage_opr(opr, &inst_src_list);
		op = ft_get_op(op_tab, op_tab[opr]->name);
		i += ft_manage_param(src + i, op, &inst_src_list, op_tab);
		ft_add_vm_instlist(inst_src_list, &vm_src);
		ft_clear_intlist(&inst_src_list);
	}
	return (vm_src);
}
