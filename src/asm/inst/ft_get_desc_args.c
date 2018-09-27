/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_desc_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:44:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 18:53:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int	get_desc_arg(char *arg)
{
	if (!arg)
		return (0);
	if (ft_is_indirect(arg))
		return (DESC_IND);
	if (ft_is_register(arg))
		return (DESC_REG);
	else //if (ft_is_direct(arg))
		return (DESC_DIR);
	return (0);
}

/*
** arg1 = pt->data;   juste pour plus de visibilite
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
			desc = get_desc_arg(pt->data);
		}
		desc = desc >> 2 | get_desc_arg(arg2);
	}
	desc = desc >> 2 | get_desc_arg(arg1);
	return (desc);
}
