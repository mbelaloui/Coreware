/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_desc_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:44:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 15:31:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int	get_ocp(char *arg)
{
	if (!arg)
		return (0);
	if (ft_is_str_indirect(arg))
		return (DESC_IND);
	if (ft_is_str_register(arg))
		return (DESC_REG);
	else if (ft_is_str_direct(arg))
		return (DESC_DIR);
	return (0);
}

/*
**	in put
**	{
**		param	<parameres of an instruction>
**	}
**
**	what the fonction do ??
**	this fonction gives a description of the parameters given
**	in parametres ** the description <make the ocp> octec
**	de codage de parametre
**
**	{
**		type_param	|	codage
**		-------------------------------
**		register	|	01
**		direct		|	10
**		indirect	|	11
**
**		ex ;	param		binary			hexa
**			 r1,:lab,%42 => 01 11 10 00  => 0x78
**	}
**
**	output
**	{
**		it's stock all the informations in the list_src of th plyaer
**		it translates instruction by instruction
**	}
*/

int			ft_get_desc_args(t_charlist *param)
{
	t_charlist	*pt;
	int			desc;
	char		*arg1;
	char		*arg2;

	arg1 = NULL;
	arg2 = NULL;
	desc = 0;
	pt = param;
	arg1 = pt->data;
	if (pt->next)
	{
		pt = pt->next;
		arg2 = pt->data;
		if (pt->next)
		{
			pt = pt->next;
			desc = get_ocp(pt->data);
		}
		desc = desc >> 2 | get_ocp(arg2);
	}
	desc = desc >> 2 | get_ocp(arg1);
	return (desc);
}
