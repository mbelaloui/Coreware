/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:17:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 16:19:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_put_inst(t_inst *inst)
{
	ft_printf("address inst {green}%d{eoc}\n\n", inst->position);
	ft_printf("label : [%s]\nop  {%s}  args [",
			inst->label, inst->opcode);
	ft_put_list_charlist_join(inst->param);
	ft_printf("]\n");
	if (inst->size[ARG1] != -1)
		ft_printf("size arg 1 \t[{yellow}%d{eoc}]\n", inst->size[ARG1]);
	if (inst->size[ARG2] != -1)
		ft_printf("size arg 2 \t[{yellow}%d{eoc}]\n", inst->size[ARG2]);
	if (inst->size[ARG3] != -1)
		ft_printf("size arg 3 \t[{yellow}%d{eoc}]\n", inst->size[ARG3]);
	if (inst->size[DESC] != -1)
		ft_printf("+ [%d] size description\n", inst->size[DESC]);
	ft_printf("size inst {green}%d{eoc}\n\n", inst->size_inst);
}
