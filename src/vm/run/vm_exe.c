/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 18:39:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	run_vm(t_url_file *url_champ, t_vm_option op_vm)
{
	t_vm	vm;

	ft_bzero(&vm, sizeof(vm));
	ft_init_vm(&vm, url_champ, op_vm);
	vm.head_list_process = ft_init_process(vm);
	ft_init_mem(&vm, vm.head_list_process);
	vm.op_vm = &op_vm;
	if (op_vm.v)
		ft_put_mem(vm.mem);
	else if (op_vm.g)
		ft_init_windows(&vm);
	if (vm.head_list_process)
		ft_fight(&vm);
	ft_put_winer(&vm);
	ft_dell_vm(&vm);
}

int			main(int argc, char **argv)
{
	t_vm_option	op_vm;
	t_url_file	*info_champ;
	char		*str;
	char		**tab;
	int			pt;

	if (argc == 1)
	{
		ft_error_param_vm(ERROR_NO_PARAM, " ");
		ft_put_usage_vm();
	}
	ft_init_vm_option(&op_vm);
	if (!(str = ft_mat_to_str(argv, 1)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if (!(tab = ft_strsplit(str, ' ')))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	pt = ft_search_for_op(tab, &op_vm);
	info_champ = ft_get_id_champ(tab + pt);
	if (info_champ)
		run_vm(info_champ, op_vm);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
