/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:55:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/11 12:15:33 by mbelalou         ###   ########.fr       */
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

# define T_REG_P1					0x1
# define T_DIR_P1					0x2
# define T_IND_P1					0x4

# define T_REG_P2					0x8
# define T_DIR_P2					0x10
# define T_IND_P2					0x20

# define T_REG_P3					0x40
# define T_DIR_P3					0x80
# define T_IND_P3					0x100

typedef	struct		s_instruction
{
	char			*label;
	char			*opcode;
	t_charlist		*param;
}					t_instruction;

typedef struct		s_player
{
	char			*name;
	char			*description;
	t_charlist		*comment;
	t_charlist		*file;
	t_instruction	*instructioms;
}					t_player;

void				ft_error_param(int error, char *param);

BOOL				ft_is_option(const char option);
void				ft_set_options(char c, unsigned long *op);
BOOL				ft_is_good_format_urlfile(char *url_file);
void				ft_is_good_format_param(char *url_file);

#endif
