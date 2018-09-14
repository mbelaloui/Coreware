/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_desc_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:05:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 17:26:07 by mbelalou         ###   ########.fr       */
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

void			ft_put_desc_param(t_op *op_tab[17])
{
	int i;

	i = 0;
	ft_printf("operation table / descption param :\n");
	ft_printf("| --------------------\t|\t----\t|\t---------\t|\t-----------\t"
			"\t|\n");
	ft_printf("| Operation mnemonique\t|\tName\t|\tNbr param\t|\tdescription\t"
			"\t|\n");
	ft_printf("| --------------------\t|\t----\t|\t---------\t|\t-----------\t"
			"\t|\n");
	while (i < 17 && *op_tab)
	{
		ft_printf("|\t%#.2X\t\t|\t%s\t|\t    %d\t\t|\t",
			op_tab[i]->mnemonique, op_tab[i]->name, op_tab[i]->nbr_param);
		(op_tab[i]->desc_param) ? ft_printf("need the OPC\t\t|\n")
			: ft_printf("don't need the OPC\t|\n");
		i++;
	}
	if (!i)
		vide();
	ft_printf("| --------------------\t|\t----\t|\t---------\t|\t-----------\t"
		"\t|\n");
}
