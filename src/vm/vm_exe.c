/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:22:42 by mbelalou         ###   ########.fr       */
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

/*******************************************************************************/
		//ft_init_vm.c
/*******************************************************************************/
void	ft_init_vm(t_url_file *url_champ)
{
	t_op		*op_tab[NBR_OP];
	t_champ		*champ;
//	t_listchamp		*temp_node;
	int			fd;
	t_listchamp *listchamp;

	listchamp = NULL;
	if (ft_size_url_champ(url_champ) > 4)
		ft_error_param_vm(ERROR_BAD_NBR_FILE, " ");
	ft_get_op_tab(op_tab);
	while (url_champ)
	{
		ft_printf("reading [{green}%s{eoc}]\n", url_champ->url);
		fd = ft_open_r_file(url_champ->url); 
		champ = ft_read_champ_file(fd, url_champ->id, op_tab);
	//	if (!(temp_node = ft_new_listchamp(champ)) )// || !list)
	//		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	//	ft_printf("{cyan}%s{eoc}", champ->name);
//		ft_add_champ_champlist(champ , &listchamp);
		ft_dell_champ(&champ);
		url_champ = url_champ->next;
	}
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
		ft_init_vm(info_champ);
	else
		ft_error_param_vm(ERROR_NO_SRC_FILE, " ");
	ft_dell_list_urllist(&info_champ);
	return (ft_strdel(&str) && ft_free_mat(&tab) && 0);
}
