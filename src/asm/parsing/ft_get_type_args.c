/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:40:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/05 13:07:40 by mbelalou         ###   ########.fr       */
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
**	in put
**	{
**		arg	<argument>
**		pos	<position of the argument in the instruction>
**	}
**
**	what the fonction do ??
**	this function returns the value corresponding to the argument
**	and to its position in the instruction
**	{
**		[p3]	[p2]	[p1]
**		[000]	[000]	[000]
**		ex : and r2, %42, r1
**			ft_get_type_arg([%42], pos = 2)
**			will return 	T_DIR_P2	==	000 100 000
**	}
**
**	output	please refer to the op.h to get the value of variable T_*_P<*>
**	{
**		if the argunemt is a register	T_REG_P<pos>
**		if the argunemt is a direct		T_DIR_P<pos>
**		if the argunemt is a indirect	T_IND_P<pos>
**		if the argument is every thing else 0
**	}
*/

int			ft_get_type_args(char *arg, int pos)
{
	pos++;
	if (ft_is_str_register(arg))
		return (get_id_pos_register(pos));
	else if (ft_is_str_indirect(arg))
		return (get_id_pos_indirect(pos));
	else if (ft_is_str_direct(arg))
		return (get_id_pos_direct(pos));
	return (0);
}
