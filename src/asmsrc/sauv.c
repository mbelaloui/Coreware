/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:02:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/11 19:45:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

BOOL	get_name(char *name, char *str)
{
	int i;

	i = 0;
	if (str[i] == DELIMITEUR)
		i++;
	else
	{
		ft_printf("ERROR bad paramettre format no <\" \">\n"
			"expected  <{red}%s {eoc}\"%s\">\n"
			"found     <{red}%s %s{eoc}>",NAME_CMD_STRING, NAME_CMD_PARAM, NAME_CMD_STRING, str);
		exit(0);
	}
	//if (ft_is_c_in_str(DELIMITEUR, str + i))
	char *ret;
	if ((ret = ft_strchr(str + i, DELIMITEUR)))
	{
		if (ft_strlen(ret) > 1)
			ft_printf("voir si c'est pas un comment<%s>\n", ret );
		ft_printf("param <%s>\t\tret <%s>\n", str + i, ret + 1);
	}
	else
	{
		ft_printf("ERROR bad paramettre format no <\" \">\n"
			"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
			"found     <{red}%s %s{eoc}>",NAME_CMD_STRING, NAME_CMD_STRING, str);
		exit(0);
	}
	name = str;
	return (T);
}

void	ft_get_head_comment(t_player *player, int fd)
{
	char *line;

	line = NULL;

	// get name
	get_next_line(fd, &line);// && line && line[0] == '#') || !ft_strlen(line))
	if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) 
			&& line[ft_strlen(NAME_CMD_STRING)] == ' ')
	{
		get_name(player->name, line + ft_strlen(NAME_CMD_STRING) + 1);
		ft_printf("{green}OK line <%s>{eoc}", line);
	}
	else
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"// {red}<%s>{eoc}.\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s{eoc}>", NAME_CMD_STRING, line);
		exit(0);
	}
	
//	else
//		ft_printf("{red}line <%s>{eoc}", line);
	
//	ft_strdel(&line);
	
	

	/*
	t_charlist *file;
	t_charlist *comment;
	char *line;

	line = NULL;
	comment = NULL;
	file = NULL;
	get_next_line(fd, &line);
	if ((line && line[0] == '#') || !ft_strlen(line))
	{
		if (ft_strlen(line) > 0)
			ft_add_charlist(line, &comment);
		ft_strdel(&line);
		while((get_next_line(fd, &line) && line && line[0] == '#') || !ft_strlen(line))
		{
			if (ft_strlen(line) > 0)
				ft_add_charlist(line, &comment);
			ft_strdel(&line);
		}
	}
	ft_add_charlist(line, &file);
	player->file = file;
	
	ft_strdel(&line);
	player->comment = comment;*/
	(void) player;
	(void) fd;


}

void	ft_get_head_file(t_player *player, int fd)
{
/*	t_charlist *comment;
	char *line;

	line = NULL;
	comment = NULL;
	get_next_line(fd, &line);
	if (ft_strcmp(line, NAME_CMD_STRING))
			ft_printf("voila");
*/
	fd = 0;
	(void) player;
}

void	ft_read_file(int fd, t_charlist **file)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_add_charlist(line, file);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		ft_get_start_basic_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == COMMENT_CHAR_1 || str[i] == COMMENT_CHAR)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_get_start_advanced_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == COMMENT_CHAR_2 && str[i + 1] == COMMENT_CHAR_2)
				|| (str[i] == COMMENT_CHAR_2 && str[i + 1] == COMMENT_CHAR_3)
				|| (str[i] == COMMENT_CHAR_3 && str[i + 1] == COMMENT_CHAR_2))
			return (i);
		i++;
	}
	return (-1);
}

BOOL	ft_cp_list_charlist(t_charlist *src, t_charlist **dest)
{
	t_charlist *temp_dest;

	temp_dest = *dest;
	if (!src || !dest)
		return (F);
	while (src)
	{
		ft_add_charlist(src->data, &temp_dest);
		src = src->next;
	}
	*dest = temp_dest;
	return (T);
}

BOOL	ft_cut_add_charlist(char *src, int start, int max_size, t_charlist **dest)
{
	char	*line;

	if (!src || start > max_size || max_size == 0 || !dest)
		return (F);
	line = ft_strcut(src, start, max_size);
	if (!line)
		return (F);
	ft_add_charlist(line, dest);
	ft_strdel(&line);
	return (T);
}


void	ft_get_comment(t_charlist *file, t_player *player)
{
	t_charlist *comment;
	t_charlist *ret_file;
	int len_line;
	int index;

	comment = NULL;
	ret_file = NULL;
	while (file)
	{
		len_line = ft_strlen(file->data);
		if ((index = ft_get_start_basic_comment(file->data)) > -1)
		{
			if (index + 1 < len_line)
			{
				ft_cut_add_charlist(file->data, index + 1, len_line, &comment);
				ft_cut_add_charlist(file->data, 0, index, &ret_file);
			}
			else
				ft_cut_add_charlist(file->data, 0, index, &ret_file);
		}
		else
		{
			ft_add_charlist(file->data, &ret_file);
		}	
		file = file->next;
	}
//	ft_put_list_charlist(ret_file);
	ft_cp_list_charlist(ret_file, &player->file);//&player->file);
//	player->file = file;
	/*	ft_dell_list_charlist(&player->file);

	ft_printf("****************file ****************************************\n");

	ft_dell_list_charlist(&ret_file);
*/	
/*		if ((ret = ft_strstr(pt_file->data, COMMENT_STR_1)))
		{
			index = ft_get_start_advanced_comment(pt_file->data);
			{
				ft_printf("{yellow}<%s>{eoc}   ||  {green}<%s>{eoc}--\n",
						ft_strcut(pt_file->data, 0, index),
						ft_strcut(pt_file->data, index, ft_strlen(pt_file->data)));
				ft_add_charlist(line, &comment);
				line = ft_strcut(pt_file->data, 0, index);
				ft_strdel(&pt_file->data);
				pt_file->data = line;
			}
		}
		if ((ret = ft_strstr(pt_file->data, COMMENT_STR_2)))
		{
			cmt =T;
			index = ft_get_start_advanced_comment(pt_file->data);
				ft_printf("{yellow}3 <%s>{eoc}   ||  {green}<%s>{eoc}--\n",
						ft_strcut(pt_file->data, 0, index),
						ft_strcut(pt_file->data, index, ft_strlen(pt_file->data)));
				ft_add_charlist(line, &comment);
				line = ft_strcut(pt_file->data, 0, index);
				ft_strdel(&pt_file->data);
				pt_file->data = line;
			while(pt_file)
			{
				

				if ((ret = ft_strstr(pt_file->data, COMMENT_STR_3)))
				{
				index = ft_get_start_advanced_comment(pt_file->data);
				ft_printf("{yellow}<%s>{eoc}   ||  {green}<%s>{eoc}--\n",
						ft_strcut(pt_file->data, 0, index),
						ft_strcut(pt_file->data, index, ft_strlen(pt_file->data)));
				ft_add_charlist(line, &comment);
				line = ft_strcut(pt_file->data, 0, index);
				ft_strdel(&pt_file->data);
				pt_file->data = line;
		

	//	ft_printf("   *    %s\n", pt_file->data);
					cmt = F;
					break;

				
				}
				if (pt_file)
				{
//					ft_printf("   *    %s\n", pt_file->data);
					pt_file = pt_file->next;
				}
			}
			if (cmt)
			{
				ft_printf("{Yellow}warning reaches the end of the file"
						" without having closed the comment multi line\n"
						"The file may be damaged{eoc}\n");
			}
*/			
	/*		index = ft_get_start_advanced_comment(pt_file->data);
			{
				ft_printf("{yellow}<%s>{eoc}   ||  {green}<%s>{eoc}--\n",
						ft_strcut(pt_file->data, 0, index),
						ft_strcut(pt_file->data, index, ft_strlen(pt_file->data)));
				ft_add_charlist(line, &comment);
			}*/
//		}
	
			/*		cmt = T;
		//ft_printf("   *    %s\n", pt_file->data);
			// split la chaine en deux tout ce au'il ya avant le COMMENT_CHAR_3 dans le file 
			// tout ce qu'il ya apres dasn la liste de comment
			// jusqu'a touver COMMENT_CHAR_4
			// split la chaine en deux tout ce au'il ya apres le COMMENT_CHAR_4 dans le file 
			// tout ce qu'il ya avant dasn la liste de comment
//		}
*/	
//		if (pt_file)
//	}

	player->comment = comment;
}

void	run(char *url_file,t_player *player)
{
	t_charlist *file;
	int fd;

	//good format of name_file
	file = NULL;
	ft_is_good_format_param(url_file);
	fd = ft_open_r_file(url_file);
	ft_read_file(fd, &file);
	ft_get_comment(file, player);
//	ft_get_head_comment(player,fd);
	ft_printf("****************file ****************************************\n{green}");

	ft_put_list_charlist(player->file);
	ft_printf("{eoc}****************comment ****************************************\n{yellow}");
	
	ft_put_list_charlist(player->comment);

	ft_printf("{eoc}");

	ft_dell_list_charlist(&file);
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


	ft_bzero(&player, sizeof(player));
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
	ft_dell_list_charlist(&player.comment);
	ft_strdel(&param);
	return (0);
}
