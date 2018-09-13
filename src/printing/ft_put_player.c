/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:54:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 16:56:40 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_put_player(t_player *player)
{
	ft_printf("\nname\t\t\t[%s]\ndesc\t\t\t[%s]\n\nurl out_put file\t[%s]\n"
			,player->name, player->description, player->url_output);
	ft_printf("\n\n");
	ft_put_instlist(player->src);
}
