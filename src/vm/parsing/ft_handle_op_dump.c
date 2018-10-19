/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_op_dump.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:51:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 13:58:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int	ft_handle_op_dump(char **tab, t_vm_option *op_vm)
{
	if (tab[0])
		op_vm->d = ft_get_value_op(tab[0]);
	else
		ft_error_param_vm(ERROR_NO_PARAM_DUMP, " ");
	return (2);
}
