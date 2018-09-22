/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:05:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:08:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_free_player(t_player *player)
{
	ft_strdel(&player->name);
	ft_strdel(&player->description);
	ft_strdel(&player->url_output);
	ft_dell_list_instlist(&player->src);
}
