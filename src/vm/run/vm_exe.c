/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 17:50:42 by mbelalou         ###   ########.fr       */
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

void		ft_dump(t_vm *vm)
{
		ft_put_mem(vm->mem);
		exit(0);	// sortie normale du programe
}

void	run_process(t_vm *vm, t_process *process)
{
//	ft_printf("Process reated by [%d] is in [%d] \n",
//		process->id_parent, process->pc, vm->mem[process->pc][MEM_SRC]);
	


	(void) vm;
	(void) process;
}

void 			run_cycle(t_vm *vm, t_process *list_process)
{
	while (list_process)
	{
		run_process(vm, list_process);
//		ft_printf(" ", list_process->);
		list_process = list_process->next;
	}
}

void		fight(t_vm *vm, t_process *list_process)
{
	int time_total;
	int cycle_to_die;
	int time;
	int check;

	check = 1;
	cycle_to_die = CYCLE_TO_DIE;
	time_total = 0;
	while (cycle_to_die > 0)
	{
		time = 0;//cycle_to_die;
		while (time < cycle_to_die)
		{
			if (time_total == vm->dump)
				break;//ft_dump(vm);
			run_cycle(vm, list_process);
		//	return ;
/*
			if ((time % 10)== 0)
				ft_printf("\n");
			ft_printf("time = {green}[%d]{eoc}\t", time);
*/			
			time ++;
			time_total++;
			//ft_visu(vm, list_process);
//			ft_put_mem(vm->mem);
			//print mem   // visu
		}
	//	if (!ft_check_survivor(list_process))
	//		ft_printf("put wine ... plus de process vivant\n");
	//	if (ft_get_total_live(list_process) >= NBR_LIVE)
	//		cycle_to_die =- CYCLE_DELTA;
		if (check == MAX_CHECKS)
		{
			cycle_to_die -= CYCLE_DELTA;
			check = 1;
		}
		else
			check++;


	}
	(void) list_process;
//	ft_printf("\n\n {red}time total = %d{eoc} \n\n",  time_total);
}


void	run_vm(t_url_file *url_champ, t_vm_option op_vm)
{
	t_vm	vm;
	t_process *list_process;

	list_process = NULL;
	ft_bzero(&vm, sizeof(vm));
	ft_init_vm(&vm, url_champ, op_vm);
	list_process = ft_init_process(vm);

//	ft_printf("{red}-------------------------------------------\n{eoc}");
//	ft_put_process(list_process);
//	ft_put_mem(vm.mem);
	ft_init_mem(&vm, list_process);
	fight(&vm, list_process);
	ft_put_mem(vm.mem);

	ft_dell_list_process(list_process);
//	ft_put_vm(&vm);
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

	if (info_champ)
		run_vm(info_champ, op_vm);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
