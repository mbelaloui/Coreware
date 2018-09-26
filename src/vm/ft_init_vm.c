/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:53:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 11:55:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	ft_init_vm(t_url_file *url_champ, t_vm_option op_vm)
{
	t_op	*op_tab[NBR_OP];
	t_champ	*champ;
	t_vm	vm;
	int		fd;

	ft_bzero(&vm, sizeof(vm));
	if ((vm.nbr_champ = ft_size_url_champ(url_champ)) > 4)
		ft_error_param_vm(ERROR_BAD_NBR_FILE, " ");
	ft_get_op_tab(op_tab);
	vm.dump = op_vm.d;
	while (url_champ)
	{
		fd = ft_open_r_file(url_champ->url);
		champ = ft_read_champ_file(fd, url_champ->id, op_tab);
		ft_add_champ(champ, &(vm.champs));
		url_champ = url_champ->next;
	}
	ft_put_vm(&vm);
	ft_dell_vm(&vm);
	ft_free_optab(op_tab);
}
