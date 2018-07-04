/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:24:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/04 18:09:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

static	void	vide(void)
{
	ft_printf("|\t  [∅]\t\t|\t ");
	ft_printf("[∅]\t|\t   ");
	ft_printf("[∅]\t\t|\t ");
	ft_printf("[∅]\t|\t");
	ft_printf("  [∅]   \t|\n");
}

void			ft_put_op(t_op *op_tab[17])
{
	int i;

	i = 0;
	ft_printf("operation table :\n");
	ft_printf("|--------------------\t|\t----\t|\t---------\t|\t-----\t|\t----"
			"--\t\t|\n");
	ft_printf("|Operation mnemonique\t|\tName\t|\tNbr param\t|\tCycle\t|\t par"
			"am\t\t|\n");
	ft_printf("|--------------------\t|\t----\t|\t---------\t|\t-----\t|\t----"
			"--\t\t|\n");
	while (i < 17 && *op_tab)
	{
		ft_printf("|\t%#.2X\t\t|\t", op_tab[i]->mnemonique);
		ft_printf("%s\t|\t    ", op_tab[i]->name);
		ft_printf("%d\t\t|\t  ", op_tab[i]->nbr_param);
		ft_printf("%d\t|\t", op_tab[i]->cycle);
		ft_printf("%.9b\t|\n", op_tab[i]->param);
		i++;
	}
	if (!i)
		vide();
	ft_printf("|--------------------\t|\t----\t|\t---------\t|\t-----\t|\t----"
			"--\t\t|\n");
}
