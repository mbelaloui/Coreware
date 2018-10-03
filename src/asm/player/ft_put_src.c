/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_src.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:25:22 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 14:15:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

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

/*
**	finale passe
**
**	in put
**	{
**		player	<The structure where we have the data of the champion>
**		fd		<file descriptor of out_put file>
**	}
**
**	what the fonction do ??
**	this function write the source code description of the player in
**		 the corresponding  .cor file
**
**		-	format INST
**		 	{
**				1 - {instruction [OCP] [arguments]}
**				2 - {instruction [argument]}
**			}
**
**	output
**	{
**		write the source code in the file URL_FILE.cor
**	}
*/

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
