/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 15:15:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
**void	put_op(t_vm_option *op_vm)
**{
**	ft_printf(" a = [%s]  \n", (op_vm->a) ? "ok" : "--");
**	ft_printf(" d = [%s]  \n", (op_vm->d >= 0) ? "ok" : "--");
**	ft_printf(" h = [%s]  \n", (op_vm->h) ? "ok" : "--");
**	ft_printf(" n = [%s]  \n", (op_vm->n) ? "ok" : "--");
**	ft_printf(" v = [%s]  \n", (op_vm->v) ? "ok" : "--");
**	ft_printf(" d = [%d]  \n", (op_vm->d));
**}
*/

BOOL	start()  //a revoir cette fonction
{
	char *line;

	line = NULL;
	get_next_line(STD_IN, &line);
	ft_strdel(&line);
	return (T);
}

void	ft_put_list_champ(t_champ *list_champ)
{
	while (list_champ)
	{
		ft_put_champ(list_champ);
		list_champ = list_champ->next;
	}
}



void	run_vm(t_url_file *url_champ, t_vm_option op_vm)
{
	t_vm	vm;
	t_process *list_process;

	list_process = NULL;
	ft_bzero(&vm, sizeof(vm));
	ft_init_vm(&vm, url_champ, op_vm);
	vm.head_list_process = ft_init_process(vm);
	list_process = vm.head_list_process;
	ft_init_mem(&vm, vm.head_list_process);
	//condition pour si ont veu voir le visu clasique if (op->blabla)  ou mettere cette action dasn ft_fight

	ft_put_mem(vm.mem);

//	exit(0);

	//if (start() && vm.head_list_process) tant que gnl n'est pas opti
	if (vm.head_list_process)
		ft_fight(&vm);
//	ft_put_winner(vm); tester ici
//	ft_dell_list_process(list_process);
	ft_dell_vm(&vm);
}


int	main(int argc, char **argv)
{
	t_vm_option	op_vm;
	t_url_file	*info_champ;
	char		*str;
	char		**tab;
	int			pt;

	if (argc == 1)
		ft_error_param_vm(ERROR_NO_PARAM, " ");
	ft_init_vm_option(&op_vm);
	if (!(str = ft_mat_to_str(argv, 1)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if (!(tab = ft_strsplit(str, ' ')))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	pt = ft_search_for_op(tab, &op_vm);
	info_champ = ft_get_id_champ(tab + pt);

//	ft_put_url_file(info_champ);
//	exit(0);

	if (info_champ)
		run_vm(info_champ, op_vm);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
