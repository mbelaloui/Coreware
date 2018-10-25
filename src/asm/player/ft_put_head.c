/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_head.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:17:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 14:15:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static void	put_name(t_player *player, int fd)
{
	char *str;

	str = ft_strnew(PROG_NAME_LENGTH);
	ft_strlcat(str, player->name, ft_strlen(player->name) + 1);
	write(fd, str, PROG_NAME_LENGTH);
	ft_strdel(&str);
}

static void	put_size(t_player *player, int fd)
{
	unsigned char		*ret;
	int					i;

	ret = ft_int_to_byts(ft_get_size_program(player->src), 4);
	i = 0;
	while (i < 4)
	{
		write(fd, &ret[i], 1);
		i++;
	}
	free(ret);
}

static void	put_comment(t_player *player, int fd)
{
	char *str;

	str = ft_strnew(PROG_COMMENT_LENGTH);
	ft_strlcat(str, player->description,
			ft_strlen(player->description) + 1);
	write(fd, str, PROG_COMMENT_LENGTH);
	ft_strdel(&str);
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
**	this function write the head description of the player in the corresponding
**	 .cor file
**
**		-	format head
**	 	{
**			elemnt		|		size
**			--------------------------------
**			MAGIC_NUM	|		4/oct
**			NAME		|		PROG_NAME_LENGTH/oct
**			NULL		|		4/oct
**			SIZE		|		4/oct
**			CMMENT		|		PROG_COMMENT_LENGTH/oct
**			NULL		|		4/oct
**		}
**	NB: please refer to the op.h to
**		 find the value of PROG_COMMENT_LENGTH/PROG_NAME_LENGTH
**
**	output
**	{
**		write the head in the file URL_FILE.cor
**	}
*/

void		ft_put_head(t_player *player, int fd)
{
	ft_put_bynary(COREWAR_EXEC_MAGIC, 4, fd);
	put_name(player, fd);
	ft_put_bynary(0, 4, fd);
	put_size(player, fd);
	put_comment(player, fd);
	ft_put_bynary(0, 4, fd);
}
