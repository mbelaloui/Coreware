/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:40:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 18:53:29 by mbelalou         ###   ########.fr       */
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
** utiliser les printf pour afficher le type des variables
** dans la vm !!!!
*/

int			ft_get_type_args(char *arg, int pos)
{
	if (ft_is_direct(arg))
		return (get_id_pos_direct(pos + 1));
	if (ft_is_indirect(arg))
		return (get_id_pos_indirect(pos + 1));
	if (ft_is_register(arg))
		return (get_id_pos_register(pos + 1));
	return (0);
}
