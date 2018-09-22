/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 14:37:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	put_champ(t_champ *champ)
{
	ft_printf("\nname {green}ok %s\n{eoc}", champ->name);
	ft_printf("\nsize {green} %d {eoc}\n", champ->size);
	ft_printf("\ncomment {green}ok %s\n{eoc}", champ->comment);
}

BOOL	ft_dell_inst_src(t_vm_inst **to_free)
{
	t_vm_inst *pt;

	if (!to_free || !(*to_free))
		return (F);
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		*to_free = (*to_free)->next;
		ft_clear_intlist(&(pt->src));
	}
	*to_free = NULL;
	return (T);
}

void	ft_dell_champ(t_champ **champ)
{
	char *name;
	char *com;

	name = (*champ)->name;
	ft_strdel(&name);
	com = (*champ)->comment;
	ft_strdel(&com);
//	ft_dell_inst_src(&(*champ)->src);
	free(*champ);
}


t_champ	*read_file(int fd, t_op*op_tab[NBR_OP])
{
	t_champ	*champ;

	ft_get_vm_magic(fd);
	if (!(champ = malloc(sizeof(*champ))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	champ->name = ft_get_vm_name(fd);
//	ft_strdel(&(champ)->name);
	if (ft_is_null(fd))
	{
		champ->size = ft_get_vm_size(fd);
		champ->comment = ft_get_vm_comment(fd);
//		ft_strdel(&(champ)->comment);
		if (ft_is_null(fd))
			ft_get_vm_src(fd, champ, op_tab);
		else
			ft_error_reading_file(ERROR_FORMAT_FILE);
	}
	else
		ft_error_reading_file(ERROR_FORMAT_FILE);
	
	ft_dell_champ(&champ);
	
	return (champ);
}

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
	/*champ = */read_file(fd, op_tab);
/*
	ft_strdel(&(champ)->name);
*/
//	ft_dell_champ(&champ);
	ft_free_optab(op_tab);
//	(void) champ;
	(void) argc;
	return (0);

}
