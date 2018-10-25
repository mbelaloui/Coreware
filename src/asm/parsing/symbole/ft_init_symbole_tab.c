/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_symbole_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:53:40 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/30 20:55:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

/*
**	in put
**	{
**		player	<The structure where we have the data of the champion>
**		op		<option struct>
**	}
**
**	what the fonction do ??
**	this function get a table of declared label in the source code
**
**	output
**	{
**		get a lable of declared label
**	}
*/

t_symbole	*ft_init_symbole_tab(t_player *player, t_option *op)
{
	t_instlist	*sc;
	t_symbole	*symbole;
	int			add;

	add = 0;
	symbole = NULL;
	sc = player->src;
	while (sc)
	{
		if (sc->data->label)
			ft_add_symbole(sc->data->label, add, &symbole, op);
		add += sc->data->size_inst;
		sc = sc->next;
	}
	return (symbole);
}
