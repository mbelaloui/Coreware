/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:09:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 13:24:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	set_data(t_inst *inst, t_op *op_tab[NBR_OP], t_symbole *symbole)
{
	t_op	*op;
	int		desc;
	int		i;

	i = 0;
	desc = 0;
	inst->add = malloc(sizeof(int) * inst->size_inst);
	op = ft_get_op(op_tab, inst->opcode);
	inst->add[i++] = op->mnemonique;
	if (inst->size[DESC] != -1)
	{
		desc = ft_get_desc_args(inst->param);
		inst->add[i++] = desc;
	}
	ft_get_arg_translat(inst, symbole, inst->add, i);
}

static void	run_translate(t_instlist *src, t_op *op_tab[NBR_OP],
		t_symbole *symbole)
{
	t_instlist *pt;

	pt = src;
	while (pt)
	{
		if (pt->data->opcode)
		{
			ft_get_size_bin_inst(pt->data->size);
			set_data(pt->data, op_tab, symbole);
		}
		pt = pt->next;
	}
}

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
