/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_src.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:25:22 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:26:31 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

static void	put_binary_args(t_inst *inst, int fd)
{
	t_charlist	*arg;
	int			y;
	int			i;

	arg = inst->param;
	i = 1;
	ft_put_bynary(inst->add[i], inst->size[DESC], fd);
	i++;
	y = 0;
	while (arg)
	{
		ft_put_bynary(inst->add[i], inst->size[ARG1 + y], fd);
		i++;
		y++;
		arg = arg->next;
	}
}

void		ft_put_src(t_player *player, int fd)
{
	t_instlist	*pt;
	int			i;

	pt = player->src;
	while (pt)
	{
		i = 0;
		if (pt->data->opcode)
		{
			ft_put_bynary(pt->data->add[i],
					pt->data->size[OPPR], fd);
			if (pt->data->size[DESC] == -1)
				ft_put_bynary(pt->data->add[1],
						pt->data->size[ARG1], fd);
			else
				put_binary_args(pt->data, fd);
		}
		pt = pt->next;
	}
}
