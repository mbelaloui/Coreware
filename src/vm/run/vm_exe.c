/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mint <mint@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/09 17:59:47 by mint             ###   ########.fr       */
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

//initialiser la premiere action en lui donnant une coleur des le depart
/********************************************************************************/



int		get_size_type(int id_opr, int arg, t_op *op_tab[NBR_OP])
{
//	ft_printf(" {green} aasidjaosindiasn   arg = %d {eoc}", arg);
	if (arg == REG_CODE)
		return (REG_SIZE);
	else if (arg == IND_CODE)
		return (IND_SIZE);
	else if (arg == DIR_CODE)
		return (op_tab[id_opr]->size_label);
	return (0);
}

int		get_size(int id_opration, t_op *op_tab[NBR_OP])
{
	return (get_size_type(id_opration, DIR_CODE , op_tab));
}
/*
void	process_desc_ko(int id_opration, t_op *op_tab[NBR_OP], t_vm *vm, t_process *process)
{

			ft_printf(" operation name  [%s]   OCP [%s]  \n", 
		op_tab[id_opration]->name, "don't need description");

			process->pc = (process->pc + 1) % MEM_SIZE;

	//int ocp =  vm->mem[process->pc + 1][MEM_SRC];


	int pt = 0;

		if (process->id_parent == PLAYER_1)
			ft_printf("{green}");
		else if (process->id_parent == PLAYER_2)
			ft_printf("{red}");
		else if (process->id_parent == PLAYER_3)
			ft_printf("{cyan}");
		else if (process->id_parent == PLAYER_4)
			ft_printf("{yellow}");

	int max = get_size(id_opration, op_tab);

	ft_printf(" max = [%d]  pt = [%d] ", max, pt);

	while (pt < max)
	{
			ft_printf(" %.02x ", vm->mem[process->pc][MEM_SRC]);
			pt++;
			process->pc = (process->pc + 1) % MEM_SIZE;
//			process->pc = (process->pc + 1) % MEM_SIZE;
	}
	ft_printf("{eoc}\n");
}


*/
/*
int		get_size_desc(int id_opration, int desc, t_op *op_tab[NBR_OP])
{
	int cp;

	cp = 0;
	if (desc & MASK_PARAM)
		cp += get_size_type(id_opration, (desc & MASK_PARAM) >> 6, op_tab);
	desc = desc << 2;
	if (desc & MASK_PARAM)
		cp += get_size_type(id_opration, (desc & MASK_PARAM) >> 6, op_tab);
	desc = desc << 2;
	if (desc & MASK_PARAM)
		cp += get_size_type(id_opration, (desc & MASK_PARAM) >> 6, op_tab);
	desc = desc << 2;
	return (cp);
}

*/

char	*get_name_type(int arg)
{
	if (arg == REG_CODE)
		return (ft_strdup("registre"));
	else if (arg == IND_CODE)
		return (ft_strdup("indirect"));
	else if (arg == DIR_CODE)
		return (ft_strdup("direct"));
	return(NULL);
}

void	put_opr_exe(t_opr_exe *opr, t_op *op_tab[NBR_OP])
{
	int pt;

	pt = 0;
	char*name;

	ft_printf("operations [%s] type arg[", op_tab[opr->id_opr]->name);
	while (pt < op_tab[opr->id_opr]->nbr_param)
	{
		name = get_name_type(opr->type_arg[pt]);
		ft_printf("{green}%s{eoc}", name);
		ft_strdel(&name);
		pt++;
		if (pt < op_tab[opr->id_opr]->nbr_param)
		ft_printf(", ");
	}
	ft_printf("] size [");
	pt = 0;
	while (pt < op_tab[opr->id_opr]->nbr_param)
	{
		ft_printf("{green}%d{eoc}", opr->size_arg[pt]);
	//	ft_strdel(&name);
		pt++;
		if (pt < op_tab[opr->id_opr]->nbr_param)
			ft_printf(", ");
	}
	ft_printf("]  value [");
	pt = 0;
	while (pt < op_tab[opr->id_opr]->nbr_param)
	{
		ft_printf("{green}%.2x{eoc}", (unsigned char)opr->vale_arg[pt]);
//		ft_printf("{green}%d{eoc}", opr->vale_arg[pt]);
	//	ft_strdel(&name);
		pt++;
		if (pt < op_tab[opr->id_opr]->nbr_param)
			ft_printf(", ");
	}
	ft_printf("]\n");

}
/******************************************************************************************/

int		get_nbr_param(int desc)
{
	int cp;

	cp = 0;
	while (desc & MASK_PARAM)
	{
		cp ++;
		desc = desc << 2;
	}
	return (cp);
}

void	set_size_arg(t_opr_exe *opr_exe, t_op *op_tab[NBR_OP])
{
	int pt;

	pt = 0;
	while (pt < opr_exe->nbr_param)
	{
		opr_exe->size_arg[pt] = get_size_type(opr_exe->id_opr, opr_exe->type_arg[pt], op_tab);
		pt ++;
	}
	
}

void	set_desc_arg(int ocp, int nbr_param, t_opr_exe *opr_exe)
{
	int param;
	int desc;
	
	param = 0;
	while (param < nbr_param)
	{
		desc = (ocp & MASK_PARAM) >> 6;
		if (desc == REG_CODE)
			opr_exe->type_arg[param] = REG_CODE;
		else if (desc == IND_CODE)
			opr_exe->type_arg[param] = IND_CODE;
		else if (desc == DIR_CODE)
			opr_exe->type_arg[param] = DIR_CODE;
		ocp = ocp << 2;
		param++;
	}
}


int		get_reg_val_arg(int val) // pour aue sa soit plus coherent si non on aurai pu enlever cette fonction
{

	return (val);
}

int		get_ind_val_arg(int val1, int val2) // a optimiser
{
	int ret;

	ret = 0;
	ret = ret | val1;
	ret = ret << 8;
	ret = ret | val2;
	return (ret);
}

int		get_dir_val_arg(int val1, int val2, int val3, int val4) // a optimiser
{
	int ret;

	ret = 0;
	ret = ret | val1;
	ret = ret << 8;
	ret = ret | val2;
	ret = ret << 8;
	ret = ret | val3;
	ret = ret << 8;
	ret = ret | val4;
	
//	(((b[0] << 8) | ) << 8) ;
	return (ret);
}

//	return ((((((b[0] << 8) | b[1]) << 8) | b[2]) << 8) | b[3]);

int	set_vale_arg(t_vm *vm, int pc, t_opr_exe *opr)
{
	int param;
	
	param = 0;
	while (param < opr->nbr_param)
	{
		if (opr->size_arg[param] == REG_SIZE)
			opr->vale_arg[param] = get_reg_val_arg(vm->mem[pc][MEM_SRC]);


		else if (opr->size_arg[param] == IND_SIZE)
			opr->vale_arg[param] =
			 get_ind_val_arg(vm->mem[pc][MEM_SRC], vm->mem[pc + 1][MEM_SRC]);


		else if (opr->size_arg[param] == DIR_SIZE)
			opr->vale_arg[param] = 
			get_dir_val_arg(vm->mem[pc][MEM_SRC], vm->mem[pc + 1][MEM_SRC],
			 vm->mem[pc + 2][MEM_SRC], vm->mem[pc + 3][MEM_SRC]);

	//	ft_printf("pc = %d     +%d    ",pc, opr->size_arg[param]);
		pc = ((pc + opr->size_arg[param]) % MEM_SIZE);
	//	ft_printf("  ==>     pc = %d     ",pc);
		param++;
	}
	return (pc);
}


void	process_desc_ok(t_opr_exe *opr_exe , t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
//	ft_byts_to_int();
/*	ft_printf(" operation name  [%s]   OCP [%s] {%.8b} \n",
		op_tab[opr_exe->id_opr]->name, "need description",
		vm->mem[process->pc][MEM_SRC]);
*/
	int ocp =  vm->mem[process->pc][MEM_SRC];//  asuprimer plus tard
	process->pc = (process->pc + 1) % MEM_SIZE; // already got the description

	//int max = get_size_desc(opr_exe->id_opr, ocp, op_tab);
	
	opr_exe->nbr_param = get_nbr_param(ocp);

	set_desc_arg(ocp, opr_exe->nbr_param , opr_exe);
	// il faut imperativement appler la fonction <set_desc_arg> avant <set_size_arg>
 	set_size_arg(opr_exe, op_tab);
		//reste a faire 
	process->pc = set_vale_arg(vm, process->pc, opr_exe);




//	put_opr_exe(opr_exe, op_tab);

	ft_printf("pc = %d {eoc}\n", process->pc);
}


void	process_desc_ko(t_opr_exe *opr_exe , t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process)
{
/*		ft_printf(" operation name  [%s]   OCP [%s] {%.8b} \n",
		op_tab[opr_exe->id_opr]->name, "don't need description",
		vm->mem[process->pc][MEM_SRC]);
*/

	opr_exe->nbr_param = 1;
//	opr_exe->type_arg[0] = DIR_CODE;
	opr_exe->size_arg[0] = op_tab[opr_exe->id_opr]->size_label;

	process->pc = set_vale_arg(vm, process->pc, opr_exe);


//	put_opr_exe(opr_exe, op_tab);

	ft_printf("pc = %d {eoc}\n", process->pc);


}


void	run_process(t_vm *vm, t_process *process, t_op *op_tab[NBR_OP])
{
//	ft_printf("{red}\t\t**************************************************************{eoc}\n\n\n");
	t_opr_exe opr_exe;

/*	if (!(opr_exe = malloc(sizeof(opr_exe) )))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);*/
	opr_exe.id_opr = vm->mem[process->pc][MEM_SRC];

	if (opr_exe.id_opr > 0 && opr_exe.id_opr < 17)
	{
	ft_printf("Process reated by [%d] is in [%d]  cas [%.2x]",
		process->id_parent, process->pc, opr_exe.id_opr);

	process->pc = (process->pc + 1) % MEM_SIZE; // already got the name of instruction

	
	if (op_tab[opr_exe.id_opr]->desc_param)
		process_desc_ok(&opr_exe, op_tab, vm , process);
	else
//	{
		process_desc_ko(&opr_exe, op_tab, vm , process);
//		process_desc_ko();
//	}
	(void) vm;
	(void) process;
	}else if (opr_exe.id_opr == 0)
		process->pc = (process->pc + 1) % MEM_SIZE;
	else 
	{
		ft_printf("error bad operations\n");
		exit(-4465);
	}
}

/********************************************************************************/

void 			run_cycle(t_vm *vm, t_process *list_process, t_op *op_tab[NBR_OP])
{
	while (list_process)
	{
		run_process(vm, list_process, op_tab);
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
	t_op			*op_tab[NBR_OP];

	ft_get_op_tab(op_tab);
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
			run_cycle(vm, list_process, op_tab);
		//	return ;
/*
			if ((time % 10)== 0)
				ft_printf("\n");
			ft_printf("time = {green}[%d]{eoc}\t", time);
*/			
	//ft_temporize(3);
//	ft_clear_scr();
			time ++;
			time_total++;
			//ft_visu(vm, list_process);
//			ft_put_mem(vm->mem);
			//print mem   // visu

//			ft_printf("{blue}--------------------------------------{eoc}\n");

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
	ft_free_optab(op_tab);
	ft_printf("\n\n {red}time total = %d{eoc} \n\n",  time_total);
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

//	ft_put_url_file(info_champ);

	if (info_champ)
		run_vm(info_champ, op_vm);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
