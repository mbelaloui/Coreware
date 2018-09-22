/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 12:16:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

int	main(int argc, char **argv)
{
	t_vm_option	op_vm;
	t_op*op_tab[NBR_OP];
//	t_champ	*champ;
	int		fd;
	//	int		i;

	//	i = 1;
	if (argc == 1)
		ft_error_exe(ERROR_NOT_ENOUGH_PARAM); /*erreur 1 seul argu*/
	ft_init_vm_option(&op_vm);

	ft_get_op_tab(op_tab);
	fd = ft_open_r_file(argv[1]); /*a modifier a cause des bonus -h etc.. */
	/*champ = */ft_read_file(fd, op_tab);
/*
	ft_strdel(&(champ)->name);
*/
//	ft_dell_champ(&champ);
	ft_free_optab(op_tab);
//	(void) champ;
	(void) argc;
	return (0);

}
