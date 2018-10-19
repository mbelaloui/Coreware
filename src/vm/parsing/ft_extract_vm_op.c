/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_vm_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:54:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:48:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_extract_vm_op(char **tab, t_vm_option *op_vm)
{
	if (ft_strcmp(tab[0], "-h") == 0)
		ft_put_help_vm();
	else if (ft_strcmp(tab[0], "-v") == 0)
		op_vm->v = 1;
	else if (ft_strcmp(tab[0], "-g") == 0)
		op_vm->g = 1;
	else if (ft_strcmp(tab[0], "-dump") == 0)
		return (ft_handle_op_dump(tab + 1, op_vm));
	return (1);
}
