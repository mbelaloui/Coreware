/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:24:45 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:25:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_error_head(int error, char *str_file)
{
	char **sc;

	sc = ft_strsplit(str_file, SEP);
	if (error == ERROR_FORMAT_NAME || error == ERROR_FORMAT_COMMENT)
		ft_printf("{yellow}Error format description file.{eoc}\n"
				"expected <{red}%s {eoc}\"%s\">\nfound    <{red}%s{eoc}>\n"
				"NB : the description can not be empty.\n",
				(error == ERROR_FORMAT_NAME) ? NAME_CMD_STR : COMMENT_CMD_STR,
				(error == ERROR_FORMAT_NAME) ? NAME_CMD_PR : COMMENT_CMD_PR,
				sc[0]);
	else if (error == ERROR_LEN_NAME || error == ERROR_LEN_COMMENT)
		ft_printf("{red}Error{eoc}len %s should not be supperior to %d"
				" len %s file [%d]\n", (error == ERROR_LEN_NAME) ? NAME_CMD_STR
				: COMMENT_CMD_STR, (error == ERROR_LEN_NAME) ? PROG_NAME_LENGTH
				: PROG_COMMENT_LENGTH, (error == ERROR_LEN_NAME) ? NAME_CMD_STR
				:COMMENT_CMD_STR, ft_strlen(str_file));
	else
		ft_printf("{red}Error unknown param description file.{eoc}\n"
				"expected <{red}%s {eoc}\"%s\">\nfound    <{red}%s{eoc}>\n",
				(error == ERROR_HEAD_NAME) ? NAME_CMD_STR : COMMENT_CMD_STR,
				(error == ERROR_HEAD_NAME) ? NAME_CMD_PR : COMMENT_CMD_PR,
				sc[0]);
	exit(error);
}
