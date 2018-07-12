/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:02:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/12 16:28:18 by mbelalou         ###   ########.fr       */
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
		if (str[i] == COMMENT_CHAR || str[i] == COMMENT_CHAR_1)
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
	char	*temp;

	if (!src || start > max_size || max_size == 0 || !dest)
		return (F);
	line = ft_strcut(src, start, max_size);
	if (!line)
		return (F && ft_strdel(&line));
	temp = ft_format_str(line);
	ft_strdel(&line);
	ft_add_charlist(temp, dest);
	ft_strdel(&temp);
	return (T);
}

void	ft_split_sources(int index, t_charlist *file, t_charlist **comment,
		t_charlist **ret_file)
{
	int len_line;

	len_line = ft_strlen(file->data);
	if (index + 1 < len_line)
	{
		ft_cut_add_charlist(file->data, index + 1, len_line, comment);
		ft_cut_add_charlist(file->data, 0, index, ret_file);
	}
	else
		ft_cut_add_charlist(file->data, 0, index, ret_file);
}

void	ft_split_adv_sources(int index, t_charlist *file, t_charlist **comment,
		t_charlist **ret_file)
{
	int len_line;

	len_line = ft_strlen(file->data);
	if (index + 2 < len_line)
	{
		ft_cut_add_charlist(file->data, index + 2, len_line, comment);
		ft_cut_add_charlist(file->data, 0, index, ret_file);
	}
	else
		ft_cut_add_charlist(file->data, 0, index, ret_file);
}

void	ft_split_adv_end_lm_sources(int index, t_charlist *file,
		t_charlist **comment, t_charlist **ret_file)
{
	int len_line;

	len_line = ft_strlen(file->data);
	if (index)
	{
		ft_cut_add_charlist(file->data, index + 2, len_line, ret_file);
		ft_cut_add_charlist(file->data, 0, index, comment);
	}
	else
		ft_cut_add_charlist(file->data, index + 2, len_line, ret_file);
}

int		ft_get_start_advanced_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == COMMENT_CHAR_2 && str[i + 1] == COMMENT_CHAR_2))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_get_start_ml_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == COMMENT_CHAR_2 && str[i + 1] == COMMENT_CHAR_3))
			return (i);
		i++;
	}
	return (-1);
}

int		ft_get_end_ml_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == COMMENT_CHAR_3 && str[i + 1] == COMMENT_CHAR_2))
			return (i);
		i++;
	}
	return (-1);
}

t_charlist	*manage_advenced_comment(t_charlist *file, t_charlist **comment,
		t_charlist **ret_file)
{
	int index;
	char *line;

	line = NULL;
	index = ft_get_end_ml_comment(file->data);
	ft_split_adv_sources(index + 1 , file, comment, ret_file);
	file = file->next;
	while (file)
	{
		if ((index = ft_get_end_ml_comment(file->data)) > -1)
		{
			ft_split_adv_end_lm_sources(index , file, comment, ret_file);
			break;
		}
		else
			ft_split_adv_sources(index , file, comment, ret_file);
		file = file->next;
	}
	return (file);
}

void	ft_get_basic_comment(t_charlist *file, t_player *player)
{
	t_charlist *comment;
	t_charlist *ret_file;
	int index;

	comment = NULL;
	ret_file = NULL;
	while (file)
	{
		if ((index = ft_get_start_basic_comment(file->data)) > -1)
			ft_split_sources(index, file, &comment, &ret_file);
		else if ((index = ft_get_start_advanced_comment(file->data)) > -1)
			ft_split_adv_sources(index , file, &comment, &ret_file);
		else if ((index = ft_get_start_ml_comment(file->data)) > -1)
			file = manage_advenced_comment(file, &comment, &ret_file);
		else
			ft_add_charlist(file->data, &ret_file);
		file = file->next;
	}
	ft_cp_list_charlist(ret_file, &player->file);
	ft_dell_list_charlist(&ret_file);
	ft_cp_list_charlist(comment, &player->comment);
	ft_dell_list_charlist(&comment);
}

/*void	norm_file(t_charlist **file)
{
	if (!file || !(*file))
		return ;
	while (*file)
	{
		
	}
}*/

t_charlist	*clear_file(t_charlist **file)
{
	char *temp;
	t_charlist *temp_list;
	t_charlist *sauv_temp_list;

	temp_list = NULL;
	ft_cp_list_charlist(*file, &temp_list);
	ft_dell_list_charlist(file);
	sauv_temp_list = temp_list;
	while (temp_list)
	{
		temp = ft_format_str(temp_list->data);
		ft_add_charlist(temp, file);
		ft_strdel(&temp);
		temp_list = temp_list->next;
	}
	ft_dell_list_charlist(&sauv_temp_list);
	return (*file);
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
	ft_get_basic_comment(file, player);
	ft_printf("****************file ****************************************\n{green}");
	ft_put_list_charlist(player->file);
	ft_printf("****************file ****************************************\n{cyan}");
	clear_file(&player->file);
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
	ft_dell_list_charlist(&player.file);
	ft_strdel(&param);
	return (0);
}
