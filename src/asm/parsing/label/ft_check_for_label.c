/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_label.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:38:29 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 19:31:31 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

static void	handel_indirect_label(char *arg, t_symbole *symbole)
{
	if (ft_is_in_symbole(arg, symbole) > -1)
		ft_set_used_label(arg, symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg, 0, NULL);
}

static void	handel_direct_label(char *arg, t_symbole *symbole)
{
	if (ft_is_in_symbole(arg, symbole) > -1)
		ft_set_used_label(arg, symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg, 0, NULL);
}
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

void		ft_check_for_label(t_symbole *symbole, t_instlist *src,
		t_option *op)
{
	t_charlist	*args;
	t_instlist	*pt;
	char		*arg;

//	ft_put_list_symbole(symbole);

	pt = src;
	while (pt)
	{
		args = pt->data->param;
		while (args)
		{
			arg = args->data;
//			ft_printf("{green}*****************************{eoc}\n");
	//		ft_printf("arg [%s] [%c%c]", arg + 2, arg[0],arg[1]);
			if ((arg[0] == LABEL_CHAR && ft_is_label(arg + 1)))
			{
	//			ft_printf("1111    arg [%s]", arg);
				handel_indirect_label(arg + 1, symbole);
			}
			if ((arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR 
					&& (ft_is_in_symbole(arg + 2, symbole)) > -1 ))
			{
	//			ft_printf("3333    arg [%s]", arg);
				handel_label(arg + 2, symbole);
			}
			if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR
					&& ft_is_label(arg + 2))
			{
	//			ft_printf("22 arg [%s]", arg);
				
				handel_direct_label(arg + 2, symbole);
		
			}
			args = args->next;
	//		ft_printf("\n{green}yyyyyyyyyyyyyyyyyyyyyyyyyyyy{eoc}\n");
		}
		pt = pt->next;
	}
	check_symbole_tab(symbole, op);
}
