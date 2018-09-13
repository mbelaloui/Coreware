/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_symbole_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:53:40 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:59:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

t_symbole	*ft_init_symbole_tab(t_player *player, t_option *op)
{
	t_instlist *sc;
	t_symbole *symbole;
	int add;

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
