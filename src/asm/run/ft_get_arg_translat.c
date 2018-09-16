/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_translat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:13:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 14:37:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int	get_direct(t_inst *inst, char *dir, t_symbole *symbole)
{
	int add_label;

	if ((add_label = ft_is_in_symbole(dir + 1, symbole)) > -1)
		return (add_label - inst->position);
	else
		return (ft_atoi(dir));
}

static int	get_indirect(t_inst *inst, char *ind, t_symbole *symbole)
{
	int add_label;

	if ((add_label = ft_is_in_symbole(ind + 1, symbole)) > -1)
		return (add_label - inst->position);
	else
		return (ft_atoi(ind));
}

void		ft_get_arg_translat(t_inst *inst, t_symbole *symbole, int *add,
		int i)
{
	intmax_t	add_out;
	t_charlist	*pt;

	pt = inst->param;
	while (pt)
	{
		if (ft_is_direct(pt->data))
			add_out = get_direct(inst, pt->data + 1, symbole);
		else if (ft_is_indirect(pt->data))
			add_out = get_indirect(inst, pt->data, symbole);
		else if (ft_is_register(pt->data))
			add_out = ft_atoi(pt->data + 1);
		add[i++] = add_out;
		pt = pt->next;
	}
}
