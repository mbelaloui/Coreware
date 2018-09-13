/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:17:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 14:23:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	put_name(t_player *player, int fd)
{
	char *str;

	str = ft_strnew(PROG_NAME_LENGTH);
	ft_strlcat(str, player->name, ft_strlen(player->name) + 1);
	write(fd, str , PROG_NAME_LENGTH);
	ft_strdel(&str);
}

void	put_size(t_player *player, int fd)
{
	int	 i;
	unsigned int     *ret;

	ret = ft_int_to_byts(ft_get_size_program(player->src), 4);
	i = 0;
	while (i < 4)
	{
		write(fd,&ret[i] , 1);
		i++;
	}
	free(ret);
}

void	put_comment(t_player *player, int fd)
{
	char *str;

	str = ft_strnew(PROG_COMMENT_LENGTH);
	ft_strlcat(str, player->description,
			ft_strlen(player->description) + 1);
	write(fd, str , PROG_COMMENT_LENGTH);
	ft_strdel(&str);
}

void	ft_put_head(t_player *player, int fd)
{
	ft_put_bynary(COREWAR_EXEC_MAGIC, 4, fd);
	put_name(player, fd);
	ft_put_bynary(0, 4, fd);
	put_size(player, fd);
	put_comment(player, fd);
	ft_put_bynary(0, 4, fd);
}
