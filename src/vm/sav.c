/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sav.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/06 11:49:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

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

/*
**	run_vm :
**
**	in put
**	{
**		url_champ	<A list of strings, each node contains
**						 a url to a champion file>
**		op_vm	<The structure where we will store the data param of the vm>
**	}
**
**	what the fonction do ??
**	this function extract information from the binary file and save them into
**		a list of champion
**	if all the champion <the reading/parsing step> are ok
**			w'll pass to the next step and run the vm
**	else
**			w'll exit the programclear with an error message 
**	NB : this function do the syntaxique/semantique checking
**	output
**	{
**		a boolean to report that the function has successfully done his job
**		return True  if the function did all its work
**		return False if the file given is empty or null
**	}
*/

void		ft_dell_list_process(t_process *list_process)
{
	t_process *pt;

	while (list_process)
	{
		pt = list_process;
		list_process = (list_process)->next;
		free(pt);
	}
}
/*
void		ft_dell_id_process(int id, t_process *list_process)
{
	t_process *pt;

	while (list_process)
	{
		pt = list_process;
		list_process = (list_process)->next;
		free(pt);
	}
}
*//*
t_process	*ft_new_process(int id_parent, int add_start)
{
	t_process *ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id_parent = id_parent;
	ret->pc = add_start;
	ret->carry = 0;
	ft_bzero(ret->reg, sizeof (ret->reg));
	ret->reg[0] = id_parent;
	ret->next = NULL;
	return (ret);
}*/
/*
BOOL		ft_add_process(t_process *proces, t_process **list)
{
	t_process *pt_list;

	if (!(*list))
		*list = proces;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = proces;
	}
	return (T);
}

int 	get_add_start_process(int nbr_champ, int pos)
{
	if (pos == 0)
		return (0);
//	ft_printf(" size mem %d     \n", MEM_SIZE);
	if (nbr_champ == 2)
	{
	//	ft_printf(" 2 size mem %d   \n", MEM_SIZE / 2);
		return (MEM_SIZE / 2);
	}
	if (nbr_champ == 3)
	{
	//	ft_printf(" 3 size mem %d   \n", MEM_SIZE / 3);
		return (MEM_SIZE / 3);
	}	
	if (nbr_champ ==4)
	{
	//		ft_printf(" 4 size mem %d   \n", MEM_SIZE / 4);
		return (MEM_SIZE / 4);
	}
//	(void) nbr_champ;
	return (5);
}

t_process	*ft_init_process(t_vm vm)
{
	t_process *list_ret;
	int id_champ;
	t_champ *champ;
	int add_start;

	champ = vm.champs;
	list_ret = NULL;
	id_champ = 0;
	add_start = 0;
	while (id_champ < vm.nbr_champ)
	{
		add_start += get_add_start_process(vm.nbr_champ, id_champ++);
		
		ft_add_process(ft_new_process(champ->id, add_start), &list_ret);
	
		ft_printf("{red}id_champ  %d\n", champ->id);

		champ = champ->next;
	}
	
	return (list_ret);
}

void	ft_put_process(t_process *process)
{
	while (process)
	{
		ft_printf("{green} id process = %d \t id_parent  %d\t",process->reg[0], process->id_parent);
		ft_printf("add start %d{eoc}\n\n",process->pc);
		process = process->next;
	}
}
*/
/*void	ft_put_mem(int mem[MEM_SIZE][2])
{
	int pt;

	pt = 0;
	while (mem[pt][0])
	{
		if (!(pt % 64) && !pt)
			ft_printf("\n");
		ft_printf("%.2x", mem[pt][0]);
	}
}
*/

void	run_vm(t_url_file *url_champ, t_vm_option op_vm)
{
	t_vm	vm;
	t_process *list_process;

	list_process = NULL;
	ft_bzero(&vm, sizeof(vm));
	ft_init_vm(&vm, url_champ, op_vm);
	ft_put_vm(&vm);

	list_process = ft_init_process(vm);
//	ft_put_process(list_process);

//	ft_put_mem(vm.mem);

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
	if (info_champ)
		run_vm(info_champ, op_vm);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
