/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 11:50:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

/*******************************************************************************/
		//put_op.c
/*******************************************************************************/
void	put_op(t_vm_option *op_vm)
{
	ft_printf(" a = [%s]  \n", (op_vm->a) ? "ok" : "--");
	ft_printf(" d = [%s]  \n", (op_vm->d >= 0) ? "ok" : "--");
	ft_printf(" h = [%s]  \n", (op_vm->h) ? "ok" : "--");
	ft_printf(" n = [%s]  \n", (op_vm->n) ? "ok" : "--");
	ft_printf(" v = [%s]  \n", (op_vm->v) ? "ok" : "--");

	ft_printf(" d = [%d]  \n", (op_vm->d));

}


BOOL	ft_dell_vm(t_vm *vm)
{
	t_champ *temp_dell;
	t_champ *to_dell;
	int pt;

	pt = 0;

	if (!vm->champs)
		return (F);
	
	temp_dell = vm->champs;
	while (temp_dell)
	{
		to_dell = temp_dell;
		temp_dell = temp_dell->next;

//		ft_put_champ(to_dell);
		ft_dell_champ(&(to_dell));
		pt++;
	}
	return (T);
}


void	ft_put_vm(t_vm *vm)
{
	ft_printf("/ ------------------------------------------------------ \\\n");
	ft_printf("                desciption vm \n");
	ft_printf("/ ------------------------------------------------------ \\\n");
	ft_printf("\tnbr_champ                       [%d]\n", vm->nbr_champ);
	if (vm->dump < 0)
	ft_printf("\tthe memory will not be dumped\n");
	else
	ft_printf("\tdump memory at :                [%d]\n", vm->dump);
	ft_printf("/ ------------------------------------------------------ \\\n");
	ft_printf("/ ---------- printing descption of champions ----------- \\\n");
	ft_put_listchamp(vm->champs);
	ft_printf("/ ------------------------------------------------------ \\\n");
}

/*******************************************************************************/
		//ft_init_vm.c
/*******************************************************************************/
void	ft_init_vm(t_url_file *url_champ, t_vm_option op_vm)
{
	t_op		*op_tab[NBR_OP];
	t_champ		*champ;
	t_vm		vm;
	int			fd;

	ft_bzero(&vm, sizeof(vm));
	if ((vm.nbr_champ = ft_size_url_champ(url_champ)) > 4)
		ft_error_param_vm(ERROR_BAD_NBR_FILE, " ");
	ft_get_op_tab(op_tab);
	vm.dump = op_vm.d;
	while (url_champ)//pt < vm.nbr_champ)
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

/*******************************************************************************/
		//vm_exe.c
/*******************************************************************************/
int	main(int argc, char **argv)
{
	t_vm_option	op_vm;
	t_url_file	*info_champ;
	char		*str;
	char		**tab;
	int			pt;

	if (argc == 1)
		ft_error_param_vm(ERROR_NO_PARAM, " "); /*erreur 1 seul argu*/
	tab = NULL;
	ft_init_vm_option(&op_vm);
	if (!((str = ft_mat_to_str(argv, 1)) && (tab = ft_strsplit(str, ' '))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	pt = ft_search_for_op(tab, &op_vm);
	info_champ = ft_get_id_champ(tab + pt);
	if (info_champ)
		ft_init_vm(info_champ, op_vm);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
