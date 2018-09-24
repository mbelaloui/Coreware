/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:03 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/24 20:45:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

/*
   void	ft_usage_dump()
   {
   ft_printf("\t./corewar -dump NBR | NBR ∈ N.\n");
   }
   */

void	ft_display_help(void)
{
	ft_printf("%s helper :\n"
			"\t -v : run the program with a visualizator\n"
			"\t -a : allow you to put '.s' instead of '.cor' file and compile them"
			" directly with the asm program,\n\t the option '-a'"
			"must be the first parameters.\n"
			"\t\t usage: ./corewar [-a] [-vDnh] [champion1.s]\n"
			"\t -dump : dump the memory(hexa) after nbr_cycles.\n"
			"\t\t usage: ./corewar [-dump nbr_cycles] champion1.cor\n"
			"\t -n : allow to give a number to the next player\n"
			"\t\t usage : ./corewar [[-n number_champ] champion1.cor]\n"
			"", "vm" + 2);
}

void		ft_put_usage_vm(void)
{
	ft_printf("Usage :\n"
			" ./corewar {-a champ.s} {[-v] [-h] [-dump [int]] [[-n number_champ] champion_N.cor]} n ∈ [1,2,3,4].\n");
	exit(1);
}

void	put_op(t_vm_option *op_vm)
{
	ft_printf(" a = [%s]  \n", (op_vm->a) ? "ok" : "--");
	ft_printf(" d = [%s]  \n", (op_vm->d >= 0) ? "ok" : "--");
	ft_printf(" h = [%s]  \n", (op_vm->h) ? "ok" : "--");
	ft_printf(" n = [%s]  \n", (op_vm->n) ? "ok" : "--");
	ft_printf(" v = [%s]  \n", (op_vm->v) ? "ok" : "--");

	ft_printf(" d = [%d]  \n", (op_vm->d));

}

/*

*/

int		ft_get_value_op(char *str)
{
	char *tmp;
	int nb;

	if ((nb = ft_atoi_v3(str)) < 0)
		ft_error_param_vm(ERROR_NO_PARAM_ARG, " ");
	if (!(tmp = ft_itoa(nb)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	if ((ft_strcmp(tmp, str) != 0))
		ft_error_param_vm(ERROR_NO_PARAM_ARG, " ");
	free(tmp);
	return (nb);
}

int		ft_handle_op_dump(char **tab, t_vm_option *op_vm)
{
	if (tab[0])
		op_vm->d = ft_get_value_op(tab[0]);
	else
		ft_error_param_vm(ERROR_NO_PARAM_DUMP, " ");
	return (2);
}

int		ft_extract_vm_op(char **tab, t_vm_option *op_vm)
{
	if (ft_strcmp(tab[0], "-h") == 0)
		op_vm->h = 1;
	else if (ft_strcmp(tab[0], "-v") == 0)
		op_vm->v = 1;
	else if (ft_strcmp(tab[0], "-dump") == 0)
		return (ft_handle_op_dump(tab + 1, op_vm));
	/*
	   else if (ft_strcmp(tab[0], "-a") == 0)
	   ft_set_options_vm(op, 'a');
	   */
	return (1);
}

int		ft_search_for_op(char **tab, t_vm_option *op_vm)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '-' && tab[i][1] != 'n')
			i += ft_extract_vm_op(tab + i, op_vm);
		else
			return (i);
	}
	return (i);
}



BOOL	ft_manage_vm_url(char *url)
{
	char	**temp;

	if (ft_isempty(url))
		ft_error_param_vm(ERROR_NO_PARAM,url);
	temp = ft_strsplit(url, '.');
	if (ft_matlen(temp) != 2 || ft_strcmp(temp[1], FORMAT_INPUT_VM))
		ft_error_param_vm(-1, url);
	return (T);
}

char	*get_url(char **tab)
{
	if (tab[0])
	{
	
		if (ft_manage_vm_url(tab[0]))
			ft_printf(" {green} ok  %s {eoc} ", tab[0]);

		return (tab[0]);//ft_printf("url = [%s]\n",tab[0]);
	
	}
	else
		ft_error_param_vm(ERROR_NO_PARAM_ID, " ");
	return (ft_strdup("qqqqqqqqqqqqqqqqqqq"));
}

void	ft_handle_op_n(char **tab, t_champ *champ)
{
	int id;

	if (tab[0])
	{
		id = ft_get_value_op(tab[0]);
		char *url = get_url(tab + 1);
		ft_printf("id %d url = [%s]\n",id, url);
	}
	else
		ft_error_param_vm(ERROR_NO_PARAM_ID, " ");

	(void) champ;
}

void	get_id_champ(char **tab)
{
	int pt;
	t_champ champ;

	ft_bzero(&champ, sizeof(champ));
	ft_putmat(tab);
	ft_printf("\n------------------------------------------------\n");
	pt = 0;
	while (tab[pt])
	{
		if (ft_strcmp(tab[pt], "-n") == 0)
		{
			ft_handle_op_n(tab + pt + 1, &champ);
			//pt += ft_handle_op_n(tab + pt + 1, &champ);
		}
		pt++;
	}
}

/*a modifier a cause des bonus -h etc.. */
int	main(int argc, char **argv)
{
	t_vm_option	op_vm;
	char		*str;
	char		**tab;
	int			pt;
	//	t_op*op_tab[NBR_OP];
	//	t_champ	*champ;

	if (argc == 1)
		ft_error_param_vm(ERROR_NO_PARAM, " "); /*erreur 1 seul argu*/
	tab = NULL;
	ft_init_vm_option(&op_vm);
	if (!((str = ft_mat_to_str(argv, 1)) && (tab = ft_strsplit(str, ' '))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	pt = ft_search_for_op(tab, &op_vm);


	put_op(&op_vm);
	ft_printf("\n------------------------------------------------\n");

	get_id_champ(tab + pt);

	/*
	   ft_get_op_tab(op_tab);
	   fd = ft_open_r_file(argv[1]); 
	   champ = ft_read_champ_file(fd, op_tab);

	   ft_dell_champ(&champ);
	   ft_free_optab(op_tab);
	   */	
	(void) argv;
	return ( ft_strdel(&str)  && ft_free_mat(&tab));

}
