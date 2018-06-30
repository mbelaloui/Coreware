/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:55:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/29 15:12:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/inc/libft.h"

# define ERROR_BAD_PARAM			-1
# define ERROR_NO_PARAM				-2
# define ERROR_NO_URL_FILE			-3
# define ERROR_MULTIPUL_PARAM		-4
# define ERROR_WRONG_FORMAT_FILE	-5

typedef	struct		s_instruction
{
	char			*label;
	char			*opcode;
	t_charlist		*param;
}					t_instruction;

typedef struct		s_player
{
	char			*name;
	t_charlist		*comment;
	t_instruction	*instructioms;
}					t_player;

void				ft_error_param(int error, char *param);

BOOL				ft_is_option(const char option);
void				ft_set_options(char c, unsigned long *op);
BOOL				ft_is_good_format_urlfile(char *url_file);
void				ft_is_good_format_param(char *url_file);

#endif
