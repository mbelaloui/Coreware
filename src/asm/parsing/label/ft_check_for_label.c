/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:38:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:44:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

void	handel_indirect_label(char *arg, t_symbole *symbole)
{	
	if (ft_is_in_symbole(arg, symbole) > -1)
		ft_set_used_label(arg , symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg , 0, NULL);
}

void	handel_direct_label(char *arg, t_symbole *symbole)
{
	if (ft_is_in_symbole(arg, symbole) >-1)
		ft_set_used_label(arg, symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg , 0, NULL);
}

void	check_symbole_tab(t_symbole *symbole, t_option *op)
{
	while (symbole)
	{
		if (!symbole->used)
			ft_warning(WARNING_UNUSED_LAB, 0, symbole->data, op);
		symbole = symbole->next;
	}
}

void	ft_check_for_label(t_symbole *symbole, t_instlist *src, t_option *op)
{
	char *arg;
	t_charlist *args;
	t_instlist *pt;

	pt = src;
	while (pt)
	{
		args = pt->data->param;
		while (args)
		{
			arg = args->data;
			if (arg[0] == LABEL_CHAR && ft_is_label(arg + 1))
				handel_indirect_label(arg + 1, symbole);
			if  (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR
					&& ft_is_label(arg + 2))
				handel_direct_label(arg + 2, symbole);
			args = args->next;
		}
		pt = pt->next;
	}
	check_symbole_tab(symbole, op);
}
