/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inst_src_vm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:17:04 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 13:17:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_inst_src_vm(t_vm_inst *vm_src)
{
	int	num;

	num = 0;
	ft_printf("\n\nPrinting src\n");
	ft_printf("--------------------------------\n");
	while (vm_src)
	{
		ft_printf("[%.3d]\t : \t", num++);
		ft_put_hex_intlist(vm_src->src);
		ft_printf("---------------------------------------\n");
		vm_src = vm_src->next;
	}
}
