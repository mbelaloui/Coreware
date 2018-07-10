/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:02:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/10 17:56:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_get_head(t_player *player, int fd)
{
//	t_charlist *file;
	t_charlist *comment;
	char *line;

	line = NULL;
	comment = NULL;
	get_next_line(fd, &line);
	if (!ft_strlen(line))
		ft_printf("empty file \n");
	if (line && line[0] == '#')
	{
		ft_add_charlist(line, &comment);
		ft_strdel(&line);
		while(get_next_line(fd, &line) && line && line[0] == '#')
		{
			ft_add_charlist(line, &comment);
			ft_strdel(&line);
		}
	}
	ft_strdel(&line);
	player->comment = comment;
}

void	ft_read_file(int fd, t_player *player)
{
	t_charlist *file;
	char *line;

	line = NULL;
	file = NULL;

	ft_get_head(player,fd);
	while (get_next_line(fd, &line))
	{
		ft_add_charlist(line, &file);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	player->file = file;
//	return (file);
}

void	run(char *url_file,t_player *player)
{
	int fd;

	//good format of name_file
	ft_is_good_format_param(url_file);
	fd = ft_open_r_file(url_file);
	ft_read_file(fd, player);

	ft_printf("\n********************************************************\n");

	ft_put_list_charlist(player->file);
	ft_printf("\n********************************************************\n");
	
	ft_put_list_charlist(player->comment);
	//get info file and check is well formated
	//check options and print datas if mantioned
	//translate file .s to file .cor
}

int		main(int argc, char **argv)
{
	unsigned long	op;
	char			*param;
	int				pt;
	t_player		player;

	op = 0;
	param = ft_mat_to_str(argv, 1);
	pt = ft_extract_options(param, &op, ft_is_option, ft_set_options);
/*
	faire attention a l'option {-o + output } si non l'enlever carrement
	si non mettre un nom par defaut s'il ya pas un nom valide 
	s\il ya directement une url d'un fichier valide
*/
	if (pt < 0)
		ft_error_param(ERROR_BAD_PARAM, param);
	else if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else
		run(param + pt, &player);
	//ne pas oublier de free param

	ft_dell_list_charlist(&player.file);
	ft_dell_list_charlist(&player.comment);
	ft_strdel(&param);
	return (0);
}
