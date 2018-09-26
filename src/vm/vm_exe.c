/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 12:00:08 by mbelalou         ###   ########.fr       */
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
