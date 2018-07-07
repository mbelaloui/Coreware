/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_size_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:31:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 19:35:19 by mbelalou         ###   ########.fr       */
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

void			ft_put_size_label(t_op *op_tab[17])
{
	int i;

	i = 0;
	ft_printf("operation table / descption param :\n");
	ft_printf("| --------------------\t|\t----\t|\t---------\t|\t----------"
			"\t|\n");
	ft_printf("| Operation mnemonique\t|\tName\t|\tNbr param\t|\tsize Label"
			"\t|\n");
	ft_printf("| --------------------\t|\t----\t|\t---------\t|\t----------"
			"\t|\n");
	while (i < 17 && *op_tab)
	{
		ft_printf("|\t%#.2X\t\t|\t%s\t|\t    %d\t\t|\t     %d\t\t|\n",
			op_tab[i]->mnemonique, op_tab[i]->name, op_tab[i]->nbr_param,
			op_tab[i]->size_label);
		i++;
	}
	if (!i)
		vide();
	ft_printf("| --------------------\t|\t----\t|\t---------\t|\t----------"
		"\t|\n");
}
