/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:40:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 19:31:40 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int	get_id_pos_direct(int pos)
{
	if (pos == 1)
		return (T_DIR_P1);
	else if (pos == 2)
		return (T_DIR_P2);
	else
		return (T_DIR_P3);
}

static int	get_id_pos_indirect(int pos)
{
	if (pos == 1)
		return (T_IND_P1);
	else if (pos == 2)
		return (T_IND_P2);
	else
		return (T_IND_P3);
}

static int	get_id_pos_register(int pos)
{
	if (pos == 1)
		return (T_REG_P1);
	else if (pos == 2)
		return (T_REG_P2);
	else
		return (T_REG_P3);
}

/*
BOOL	is_lab(char *arg)
{
	(void)arg;
	return(T);
}
*/
/*
** utiliser les printf pour afficher le type des variables
** dans la vm !!!!
*/

int			ft_get_type_args(char *arg, int pos)
{
	pos++;
/*	ft_printf("\n\targ = %s , pos = %d ", arg, pos);

	if (ft_is_direct(arg))
		ft_printf("{green}direct{eoc}\n");
	else if (ft_is_indirect(arg))
		ft_printf("{red}indirect{eoc}\n");
	else if (ft_is_register(arg))
		ft_printf("{cyan}register{eoc}\n");
	else if (ft_is_label(arg))
		ft_printf("{yellow}label{eoc}\n");
	else if (is_lab(arg))
		ft_printf("{green} direct<label>{eoc}\n");
*/	//	ft_printf("voila voila\n");

//	if (ft_is_direct(arg))
		//return (get_id_pos_direct(pos + 1));
	
	if (ft_is_indirect(arg))
		return (get_id_pos_indirect(pos));
	else if (ft_is_register(arg))
	{
		return (get_id_pos_register(pos));
	}
	else// if (ft_is_direct(arg))
	{	
//		int d = get_id_pos_direct(pos);
//		ft_printf("    label rep  =%.9b ", d);
				return (get_id_pos_direct(pos));
	}
//	else// if (is_lab(arg))
//		return (get_id_pos_direct(pos));

//	ft_printf("{red} je fait rien{eoc}");
	return (0);
}
