/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:02:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 16:29:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 **	faire une foncion format just pour corware qui remplace les espaces par des /t
 **	just pour faire jolie
 */


#include "../../inc/op.h"

BOOL	get_name(char *str)
{
	int i;

	i = 0;
	if (str[i] == DELIMITEUR)
		i++;
	else
	{
		ft_printf("1 ERROR bad paramettre format no <\" \">\n"
				"expected  <{red}%s {eoc}\"%s\">\n"
				"found     <{red}%s %s{eoc}>",NAME_CMD_STRING, NAME_CMD_PARAM, NAME_CMD_STRING, str);
		exit(0);
	}
	char *ret;
	if ((ret = ft_strchr(str + i, DELIMITEUR)))
	{
		if (ft_strlen(ret) > 1)
		{
			ft_printf("ERROR bad paramettre format\n"
					"<{red}%s {eoc}\"%s\"> should not have characters other than"
					" comments after declaration.\n",NAME_CMD_STRING, NAME_CMD_PARAM);
			exit(0);
		}
	}
	else
	{
		ft_printf("3 ERROR bad paramettre format no <\" \">\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s %s{eoc}>",NAME_CMD_STRING, NAME_CMD_STRING, str);
		exit(0);
	}
	//name = str;
	return (T);
}

void	ft_get_head_comment(t_player *player)
{
	//char *line;
	t_charlist *file;

	file = player->file;
	//	line = NULL;

	// get name
	//	line = file->data;

	ft_printf("\n\n%s\n", file->data);

	//	get_next_line(fd, &line);// && line && line[0] == '#') || !ft_strlen(line))
	if (!ft_strncmp(file->data, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) 
			&& file->data[ft_strlen(NAME_CMD_STRING)] == ' ')
	{
		/*player->name ft_strdup()*/ get_name(file->data + ft_strlen(NAME_CMD_STRING) + 1);
		ft_printf("{green}OK line <%s>{eoc}",file->data);
	}
	else // le fichier ne commance pas avec le nom du champion
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"// {red}<%s>{eoc}.\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s{eoc}>", NAME_CMD_STRING, file->data);
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


}


void	run(char *url_file,t_player *player)
{
//	player->comment = NULL;

	ft_first_parsing(url_file, player);
	if (!player->file)
	{
		ft_printf("empty file\n");
		exit(0);	
	}
	ft_get_head_comment(player);
//	   ft_get_basic_comment(file, player);
	   ft_put_list_charlist(player->file);
	   ft_printf("{eoc}****************comment ****************************************\n{yellow}");
	   ft_put_list_charlist(player->comment);
	   ft_printf("{eoc}");
	
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
