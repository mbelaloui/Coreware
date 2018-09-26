/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extraire_head_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:32:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:46:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static int	extraire_name(char *str_file, t_player *player)
{
	int start_cmd;
	int len;
	int ret;

	ret = 0;
	start_cmd = ft_skip_spaces(str_file);
	len = start_cmd + ft_strlen(NAME_CMD_STR);
	if (!ft_strncmp(str_file + start_cmd, NAME_CMD_STR,
				ft_strlen(NAME_CMD_STR)) && str_file[len] == SPS)
	{
		len = len + ft_skip_spaces(str_file + len);
		if ((ret = ft_get_data(str_file + len, &(player->name))) < 0)
			ft_error_head(ERROR_FORMAT_NAME, str_file);
		if (ft_isempty(player->name))
			ft_error_head(ERROR_FORMAT_NAME, str_file);
		ret += len;
	}
	else
		ft_error_head(ERROR_HEAD_NAME, str_file);
	if (ft_strlen(player->name) > PROG_NAME_LENGTH)
		ft_error_head(ERROR_LEN_NAME, player->name);
	return (ret);
}

static int	extraire_description(char *str_file, t_player *player)
{
	int start_cmd;
	int len;
	int ret;

	ret = 0;
	start_cmd = ft_skip_spaces(str_file);
	len = start_cmd + ft_strlen(COMMENT_CMD_STR);
	if (!ft_strncmp(str_file + start_cmd, COMMENT_CMD_STR,
				ft_strlen(COMMENT_CMD_STR)) && str_file[len] == SPS)
	{
		len = len + ft_skip_spaces(str_file + len);
		if ((ret = ft_get_data(str_file + len,
						&(player->description))) < 0)
			ft_error_head(ERROR_FORMAT_COMMENT, str_file);
		if (ft_isempty(player->description))
			ft_error_head(ERROR_FORMAT_COMMENT, str_file);
		ret += len;
	}
	else
		ft_error_head(ERROR_HEAD_COMMENT, str_file);
	if (ft_strlen(player->description) > PROG_COMMENT_LENGTH)
		ft_error_head(ERROR_LEN_COMMENT, player->description);
	return (ret);
}

static void	restore_head(t_player *player)
{
	char *name;
	char *description;

	name = ft_replace_char_in_str(player->name, SEP, RET);
	ft_strdel(&player->name);
	player->name = name;
	description = ft_replace_char_in_str(player->description, SEP, RET);
	ft_strdel(&player->description);
	player->description = description;
}

int			ft_extraire_head_info(char *str_file, t_player *player)
{
	int pt_ret;

	pt_ret = extraire_name(str_file, player);
	pt_ret += extraire_description(str_file + pt_ret, player);
	restore_head(player);
	return (pt_ret);
}
