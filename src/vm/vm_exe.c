/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 18:22:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	put_champ(t_champ *champ)
{
	ft_printf("\nname {green}ok %s\n{eoc}", champ->name);
	ft_printf("\nsize {green} %d {eoc}\n", champ->size);
	ft_printf("\ncomment {green}ok %s\n{eoc}", champ->comment);
}

void	ft_dell_champ(t_champ **champ)
{
	ft_strdel(&(*champ)->name);
	ft_strdel(&(*champ)->comment);
	free(*champ);
}

t_champ	*read_file(int fd)
{
	t_champ	*champ;

	champ = malloc(sizeof(champ));
	champ->name = ft_get_vm_name(fd);
	if (ft_is_null(fd))
	{
		champ->size = ft_get_vm_size(fd);
		champ->comment = ft_get_vm_comment(fd);
		if (ft_is_null(fd))
		{
			ft_get_vm_src(fd, champ->size);
			//	ft_get_vm_src(fd, champ);
		}
		else
		{
			ft_printf("{red}error format head fileko{eoc}\n");
			exit(0);
		}
	}
	else
	{
		ft_printf("{red}error format head fileko{eoc}\n");
		exit(0);
	}
	return (champ);
}

int	main(int argc, char **argv)
{
	t_champ	*champ;
	int		fd;

	fd = ft_open_r_file(argv[1]);
	ft_get_vm_magic(fd);
	champ = read_file(fd);
	
	ft_dell_champ(&champ);
	(void) argc;
	return (0);

}
