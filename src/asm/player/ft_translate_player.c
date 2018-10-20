/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:09:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 15:20:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

/*
**	in put
**	{
**		inst	<structure that contain all the information about
**					 an instruction>
**		op_tab	<the table that contains the information about the instructions>
**		symbole	<list of declared label and their address>
**	}
**
**	what the fonction do ??
**	this function translate the information from assembly to binary
**
**	output
**	{
**		set the binary traduction of the instruction in the inst.add variable of
**		 the instruction structure
**	}
*/

static void	set_data(t_inst *inst, t_op *op_tab[NBR_OP], t_symbole *symbole)
{
	t_op	*op;
	int		i;

	i = 0;
	if (!(inst->add = malloc(sizeof(int) * inst->size_inst)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	op = ft_get_op(op_tab, inst->opcode);
	inst->add[i++] = op->mnemonique;
	if (inst->size[DESC] != -1)
		inst->add[i++] = ft_get_desc_args(inst->param);
	ft_get_arg_translat(inst, symbole, i);
}

static void	run_translate(t_instlist *src, t_op *op_tab[NBR_OP],
		t_symbole *symbole)
{
	t_instlist *pt;

	pt = src;
	while (pt)
	{
		if (pt->data->opcode)
			set_data(pt->data, op_tab, symbole);
		pt = pt->next;
	}
}

/*
**	seconde passe
**
**	in put
**	{
**		player	<The structure where we have the data of the champion>
**		op_tab	<the table that contains the information about the
**			 instructions>
**	}
**
**	what the fonction do ??
**	this function translate the information from assembly to binary
**
**	output
**	{
**		it's stock all the informations in the list_src of th plyaer
**		it translates instruction by instruction
**	}
*/

void		ft_translate_player(t_player *player, t_op *op_tab[NBR_OP],
		t_option *op)
{
	t_symbole *symbole;

	symbole = ft_init_symbole_tab(player, op);
	ft_check_for_label(symbole, player->src, op);
	run_translate(player->src, op_tab, symbole);
	if (op->s)
		ft_put_list_symbole(symbole);
	ft_dell_list_symbole(&symbole);
}
