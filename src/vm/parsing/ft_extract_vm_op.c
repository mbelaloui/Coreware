/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_vm_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:54:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:34:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_extract_vm_op(char **tab, t_vm_option *op_vm)
{
	if (ft_strcmp(tab[0], "-h") == 0)
		op_vm->h = 1;
	else if (ft_strcmp(tab[0], "-v") == 0)
		op_vm->v = 1;
	else if (ft_strcmp(tab[0], "-dump") == 0)
		return (ft_handle_op_dump(tab + 1, op_vm));
	return (1);
}
