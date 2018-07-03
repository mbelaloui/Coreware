/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2018/07/03 20:38:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/op.h"

t_op		*ft_new_op(int mnemonique, char *name, int nbr_param, int cycle)
{
	t_op	*ret;

	ret = malloc(sizeof(*ret));
	ret->mnemonique = mnemonique;
	ret->name = ft_strdup(name);
	ret->nbr_param = nbr_param;
	ret->param = 0;
	ret->cycle = cycle;
	return (ret);
}

void		ft_put_op(t_op *op_tab[])
{
	int i;

	i = 0;
	ft_printf("operation table :\n");
	ft_printf(" --------------------\t|\t----\t|\t---------\t|\t-----\t|\t------\t\t|\n");
	ft_printf("|Operation mnemonique\t|\tName\t|\tNbr param\t|\tCycle\t|\t param\t\n");
	ft_printf(" --------------------\t|\t----\t|\t---------\t|\t-----\t|\t------\t\t|\n");
	while (i < 17)
	{
		ft_printf("|\t%#.2X\t\t|\t", op_tab[i]->mnemonique);
		ft_printf("%s\t|\t    ", op_tab[i]->name);
		ft_printf("%d\t\t|\t  ", op_tab[i]->nbr_param);
		ft_printf("%d\t|\t", op_tab[i]->cycle);
		ft_printf("%.9b\t|\n", op_tab[i]->param);
		i++;
	}
	ft_printf(" --------------------\t|\t----\t|\t---------\t|\t-----\t|\t------\t\t|\n");
}

void		ft_int_op_tab(t_op *op_tab[17])
{
	op_tab[0] = ft_new_op(0, "NULL", 0, 0);
	op_tab[1] = ft_new_op(1, "live", 1, 10);
	op_tab[2] = ft_new_op(2, "ld", 2, 5);
	op_tab[3] = ft_new_op(3, "st", 2, 5);
	op_tab[4] = ft_new_op(4, "add", 3, 10);
	op_tab[5] = ft_new_op(5, "sub", 3, 10);
	op_tab[6] = ft_new_op(6, "and", 3, 6);
	op_tab[7] = ft_new_op(7, "or", 3, 6);
	op_tab[8] = ft_new_op(8, "xor", 3, 6);
	op_tab[9] = ft_new_op(9, "zjmp", 1, 20);
	op_tab[10] = ft_new_op(10, "ldi", 3, 25);
	op_tab[11] = ft_new_op(11, "sti", 3, 25);
	op_tab[12] = ft_new_op(12, "fork", 1, 800);
	op_tab[13] = ft_new_op(13, "lld", 2, 10);
	op_tab[14] = ft_new_op(14, "lldi", 3, 50);
	op_tab[15] = ft_new_op(15, "lfork", 1, 1000);
	op_tab[16] = ft_new_op(16, "aff", 1, 2);
}

void	ft_set_param(t_op *op_tab[17])
{
	op_tab[1]->param = T_DIR_P1;
	op_tab[2]->param = T_DIR_P1 | T_IND_P1 | T_REG_P2;
	op_tab[3]->param = T_REG_P1 | T_IND_P2 | T_REG_P2;
	op_tab[4]->param = T_REG_P1 | T_REG_P2 | T_REG_P3;
	op_tab[5]->param = T_REG_P1 | T_REG_P2 | T_REG_P3;
	op_tab[6]->param = T_REG_P1 | T_DIR_P1 | T_IND_P1 | T_REG_P2 | T_IND_P2
		| T_DIR_P2 | T_REG_P3;
	op_tab[7]->param = T_REG_P1 | T_IND_P1 | T_DIR_P1 | T_REG_P2 | T_IND_P2
		| T_DIR_P2 | T_REG_P3;
	op_tab[8]->param = T_REG_P1 | T_IND_P1 | T_DIR_P1 | T_REG_P2 | T_IND_P2
		| T_DIR_P2 | T_REG_P3;
	op_tab[9]->param = T_DIR_P1;
	op_tab[10]->param = T_REG_P1 | T_DIR_P1 | T_IND_P1 | T_DIR_P2 | T_REG_P2
		| T_REG_P3;
	op_tab[11]->param = T_REG_P1 | T_REG_P2 | T_DIR_P2 | T_IND_P2 | T_DIR_P3
		| T_REG_P3;
	op_tab[12]->param = T_DIR_P1;
	op_tab[13]->param = T_DIR_P1 | T_IND_P1 | T_REG_P2;
	op_tab[14]->param = T_REG_P1 | T_DIR_P1 | T_IND_P1 | T_DIR_P2 | T_REG_P2
		| T_REG_P3;
	op_tab[15]->param = T_DIR_P1;
	op_tab[16]->param = T_REG_P1;
}

int		ft_get_nbr_param(t_op *op)
{
	return (op->nbr_param);
}

void	ft_put_op_param_3(t_op *op)
{
	if (op->param & T_DIR_P3)
		ft_printf("{GREEN}direct{eoc}");
	if (op->param & T_REG_P3)
		ft_printf(" {RED}registre{eoc}");
	if (op->param & T_IND_P3)
		ft_printf(" {YELLOW}indirect{eoc}");
}

void	ft_put_op_param_2(t_op *op)
{
	if (op->param & T_DIR_P2)
		ft_printf("{GREEN}direct{eoc}");
	if (op->param & T_REG_P2)
		ft_printf(" {RED}registre{eoc}");
	if (op->param & T_IND_P2)
		ft_printf(" {YELLOW}indirect{eoc}");
}

void	ft_put_op_param_1(t_op *op)
{
	if (op->param & T_DIR_P1)
		ft_printf("{GREEN}direct{eoc}");
	if (op->param & T_REG_P1)
		ft_printf(" {RED}registre{eoc}");
	if (op->param & T_IND_P1)
		ft_printf(" {YELLOW}indirect{eoc}");
}

char	*ft_get_name(t_op *op_tab)
{
	return (op_tab->name);
}

int		ft_get_cycle(t_op *op_tab)
{
	return (op_tab->cycle);
}

int		ft_get_type_param(t_op *op_tab)
{
	return (op_tab->param);
}

void	ft_put_typ_param(t_op *op_tab[17])
{
	int i;

	i = 0;
	ft_printf("Parameters type :\n\n");
	while (i < 17)
	{
		ft_printf("[%s]\n\tparam 1 [", ft_get_name(op_tab[i]));
		ft_put_op_param_1(op_tab[i]);
		ft_printf("]\n\tparam 2 [");
		ft_put_op_param_2(op_tab[i]);
		ft_printf("]\n\tparam 3 [");
		ft_put_op_param_3(op_tab[i]);
		ft_printf("]\n");
		i++;
	}
}

BOOL	ft_is_type_ok(t_op *op_tab, int type)
{
	if (type & ft_get_type_param(op_tab))
		return (T);
	return (F);
}

int		main(void)
{
	t_op *op_tab[17];

	ft_int_op_tab(op_tab);
	ft_set_param(op_tab);
	ft_put_op(op_tab);
	ft_put_typ_param(op_tab);

	//  voila pour is type ok 
	//  il suffit de lui en voyer la description de op et le type de parame detecter
	ft_printf(" hellow %d \n", ft_is_type_ok(op_tab[1], T_REG_P1));
	return (0);
}
