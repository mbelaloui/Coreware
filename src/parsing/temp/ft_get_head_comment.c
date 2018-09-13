/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_head_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:13:12 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 19:26:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char	*get_name(char *str)
{
	int i;

	i = 0;
	if (str[i] == DELIMITEUR)
		i++;
	else
	{
		ft_printf("1 ERROR bad paramettre format no <\" \">\n"
				"expected  <{red}%s {eoc}\"%s\">\n"
				"found     <{red}%s %s{eoc}>",NAME_CMD_STRING,
				NAME_CMD_PARAM, NAME_CMD_STRING, str);
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
	i = 1;
	while (str[i] != DELIMITEUR)
		i++;
	return (ft_strcut(str, 1 ,i));
}

char	*get_description(char *str)
{
	int i;

	i = 0;
	if (str[i] == DELIMITEUR)
		i++;
	else
	{
		ft_printf("1 ERROR bad paramettre format no <\" \">\n"
				"expected  <{red}%s {eoc}\"%s\">\n"
				"found     <{red}%s %s{eoc}>",COMMENT_CMD_STRING,
				COMMENT_CMD_STRING, COMMENT_CMD_STRING, str);
		exit(0);
	}
	char *ret;
	if ((ret = ft_strchr(str + i, DELIMITEUR)))
	{
		if (ft_strlen(ret) > 1)
		{
			ft_printf("ERROR bad paramettre format\n"
					"<{red}%s {eoc}\"%s\"> should not have characters other than"
					" comments after declaration.\n", COMMENT_CMD_STRING, COMMENT_CMD_STRING);
			exit(0);
		}
	}
	else
	{
		ft_printf("3 ERROR bad paramettre format no <\" \">\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s %s{eoc}>",COMMENT_CMD_STRING, COMMENT_CMD_STRING, str);
		exit(0);
	}
	i = 1;
	while (str[i] != DELIMITEUR)
		i++;
	return (ft_strcut(str, 1 ,i));
}

void	manage_name(t_player *player, char *line)
{
	char *name;

	if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
			&& line[ft_strlen(NAME_CMD_STRING)] == ' ')
	{
		name = get_name(line + ft_strlen(NAME_CMD_STRING) + 1);
		ft_printf("{green}OK line <%s>{eoc}",line);
	}
	else // le fichier ne commance pas avec le nom du champion
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s{eoc}>", NAME_CMD_STRING, line);
		exit(0);
	}
	(void) player;
	ft_printf("\nvoila\n%s\n\n", name);
}

void	manage_param(t_player *player, char *line)
{
	char *name;

	if (!ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))
			&& line[ft_strlen(COMMENT_CMD_STRING)] == ' ')
	{
		name = get_name(line + ft_strlen(COMMENT_CMD_STRING) + 1);
		ft_printf("{green}OK line <%s>{eoc}",line);
	}
	else // le fichier ne commance pas avec le nom du champion
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s{eoc}>", COMMENT_CMD_STRING, line);
		exit(0);
	}
	(void) player;
	ft_printf("\nvoila\n%s\n\n", name);
}

void	ft_get_head_comment(t_player *player)
{
	t_charlist *file;
	char *name;
	char *comment;

	file = player->file;
	name = ft_format_str(file->data);
	manage_name(player, name);






	file = file->next;
	name = ft_format_str(file->data);
	manage_param(player, name);
/*	if (!ft_strncmp(file->data, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
			&& file->data[ft_strlen(NAME_CMD_STRING)] == ' ')
	{
//		/player->name ft_strdup() 
		get_name(file->data + ft_strlen(NAME_CMD_STRING) + 1);
		ft_printf("{green}OK line <%s>{eoc}",file->data);
	}
	else // le fichier ne commance pas avec		le nom du champion
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"
				// {red}<%s>{eoc}.\n"
				"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
				"found     <{red}%s{eoc}>", NAME_CMD_STRING, file->data);
		exit(0);
	}
*/	(void) player;
	(void) comment;
}
