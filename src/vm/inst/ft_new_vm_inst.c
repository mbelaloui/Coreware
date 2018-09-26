/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_vm_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:32:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 18:58:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_vm_inst	*ft_new_vm_inst(t_int_list *src)
{
	t_vm_inst		*ret;

	ret = NULL;
	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->src = NULL;
	ft_cp_list_intlist(src, &(ret->src));
	ret->size = ft_size_intlist(src);
	ret->next = NULL;
	return (ret);
}
