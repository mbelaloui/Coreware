/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_out_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:27:18 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 12:37:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

/*
**	finale passe
**
**	in put
**	{
**		player	<The structure where we have the data of the champion>
**	}
**
**	what the fonction do ??
**	this function write the player in the corresponding .cue file
**
**	output
**	{
**		file URL_FILE.cor
**	}
*/

void	ft_make_out_put(t_player *player)
{
	int fd;

	if (!(fd = open(player->url_output, O_WRONLY | O_CREAT, 0666)))
		ft_error_exe(ERROR_CAN_NOT_CEART_FILE);
	ft_put_head(player, fd);
	ft_put_src(player, fd);
	ft_printf("%s {green}successfully created{eoc}\n", player->url_output);
}
