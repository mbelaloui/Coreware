/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_out_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:27:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 13:56:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	ft_make_out_put(t_player *player)
{
	int fd;

	fd = open(player->url_output, O_WRONLY | O_CREAT, 0666);
	ft_put_head(player, fd);
	ft_put_src(player, fd);
	ft_printf("%s {green}successfully created{eoc}\n", player->url_output);
}
