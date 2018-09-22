/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:53:46 by dalauren          #+#    #+#             */
/*   Updated: 2018/09/22 17:18:19 by dalauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/inc/libft.h"
#include "./inc/vm.h"
#include <stdlib.h>

void	init_op(t_vm_option *op)
{
	op->h = 0;
	op->n = 0;
	op->D = 0;
	op->v = 0;
	op->a = 0;
	op->dump_value = 0;
}

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

void	ft_set_options_vm(t_vm_option *op, char c)
{
	if (c == 'h')
		ft_display_help();
	else if (c == 'v')
		op->v = 1;
	else if (c == 'a')
		op->a = 1;
	else
	{
		ft_printf("unknown options\n");
		exit(1);
	}
}

int		get_value_op(char *str)
{
	int i;
	char *tmp;
	int nb;

	i = 0;
	nb = ft_atoi_v3(str);

	/*change en int puis repasse le int en char* pour comparer et voir si c'est
	 le meme nombre, si ce n'est pas le cas, valeur trop grande ou trop petite*/
	if (nb == -1)
	{
		ft_printf("error pas chiffre\n");
		exit(1);//error;
	}
	if (!(tmp = ft_itoa(nb)))
		exit(1); //not enough memory
	if ((ft_strcmp(tmp, str) != 0) || nb < 0)
	{
		free(tmp);
		ft_printf("error int\n");
		exit(1);
	}
	free(tmp);
	return (i);
}

void	handle_op_dump(char **tab, int i, int ac, t_vm_option *op)
{
	if (i + 1 > ac)
	{
		ft_printf("error options\n");
		exit(1);
	}
	op->D = 1;
	op->dump_value = get_value_op(tab[i + 1]);
}

void	handle_op_n(char **tab, int i, int ac, t_vm_option *op)
{
	if (i + 2 > ac)
	{
		ft_printf("error options\n");
		exit(1);
	}
	op->n = get_value_op(tab[i + 1]);
}

/*extract the option*/
/*le "-a" doit etre en premier*/
int		extract_vm_op(char **tab, int i, t_vm_option *op, int ac)
{
	if (ft_strcmp(tab[i], "-h") == 0)
		ft_set_options_vm(op, 'h');
	else if (ft_strcmp(tab[i], "-v") == 0)
		ft_set_options_vm(op, 'v');
	else if (ft_strcmp(tab[i], "-a") == 0)
		ft_set_options_vm(op, 'a');
	else if (ft_strcmp(tab[i], "-dump") == 0)
		handle_op_dump(tab, i, ac, op);
	else if (ft_strcmp(tab[i], "-n") == 0)
		handle_op_n(tab, i, ac, op);
	else
	{
		ft_printf("unknown options\n");
		exit(1);
	}
	return (0);
}

int		search_for_op(char **tab, t_vm_option *op, int ac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i][0] == '-')
			extract_vm_op(tab, i, op, ac);
		i++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_vm_option op;
	int i;
	char	*str;
	char	**tab;

	i = 0;
	init_op(&op);
	if (!(str = ft_mat_to_str(argv, 1)))
		return (-1);
	if (!(tab = ft_strsplit(str, ' ')))
		return (-1);
	i = search_for_op(tab, &op, argc);
	return (0);
} 
