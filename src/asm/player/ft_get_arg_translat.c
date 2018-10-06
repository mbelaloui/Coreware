/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg_translat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:13:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/05 11:55:36 by mbelalou         ###   ########.fr       */
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

/*
**	in put
**	{
**		inst		<structure that contain all the information about
**					 an instruction>
**		symbole		<list of declared label and their address>
**		index_param	<position of parametre in the address tab>
**	}
**
**	what the fonction do ?
**		translate the parametres in the instruction in to binary
**			and save it in the add param in the inst struct
**
**	output
**	{
**		set the binary traduction of the instruction in the inst.add
**			 variable of the instruction structure
**	}
*/

void		ft_get_arg_translat(t_inst *inst, t_symbole *symbole,
		int index_param)
{
	intmax_t	add_out;
	t_charlist	*pt;
	int			*add;

	pt = inst->param;
	add = inst->add;
	while (pt)
	{
		if (ft_is_str_register(pt->data))
			add_out = ft_atoi(pt->data + 1);
		else if (ft_is_str_indirect(pt->data))
			add_out = get_indirect(inst, pt->data, symbole);
		else if ((ft_is_str_direct(pt->data)))
			add_out = get_direct(inst, pt->data + 1, symbole);
		else
		{
			ft_printf("je uis la \n");
			ft_error_args(ERROR_BAD_PARAM, " ", " ", pt->data);
		
		}add[index_param++] = add_out;
		pt = pt->next;
	}
}
