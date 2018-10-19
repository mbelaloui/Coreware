/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:38:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/30 20:52:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

static void	handel_label(char *arg, t_symbole *symbole)
{
	if (ft_is_in_symbole(arg, symbole) > -1)
		ft_set_used_label(arg, symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg, 0, NULL);
}

static void	check_symbole_tab(t_symbole *symbole, t_option *op)
{
	while (symbole)
	{
		if (!symbole->used)
			ft_warning(WARNING_UNUSED_LAB, 0, symbole->data, op);
		symbole = symbole->next;
	}
}

/*
**	in put
**	{
**		symbole	<list of all the declared label>
**		src	<the source code>
**	}
**
**	what the fonction do ??
**	this function check for the argument of the operations and
**		look for the used label, so we can handel the use of
**		undeclared label and unused declared label
**
**	output
**	{
**		set the used label to yes in the symbole table
**	}
*/

void		ft_check_for_label(t_symbole *symbole, t_instlist *src,
		t_option *op)
{
	t_charlist	*args;
	t_instlist	*pt;
	char		*arg;

	pt = src;
	while (pt)
	{
		args = pt->data->param;
		while (args)
		{
			arg = args->data;
			if (ft_is_str_indirect(arg) && !ft_isnumerique(arg))
				handel_label(arg + 1, symbole);
			else if (ft_is_str_direct(arg) && ft_is_str_indirect(arg + 1))
				if (!ft_isnumerique(arg + 1))
					handel_label(arg + 2, symbole);
			args = args->next;
		}
		pt = pt->next;
	}
	check_symbole_tab(symbole, op);
}
