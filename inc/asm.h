/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:55:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 16:44:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/inc/libft.h"
# include "op.h"

# define ERROR_NO_PARAM			-1
# define ERROR_MULTIPUL_PARAM		-2
# define ERROR_WRONG_FORMAT_FILE	-3
# define ERROR_READING_FILE		-4
# define ERROR_HEAD_NAME		-5
# define ERROR_HEAD_COMMENT		-6
# define ERROR_FORMAT_NAME		-7
# define ERROR_FORMAT_COMMENT		-8
# define ERROR_EMPTY_FILE		-9
# define ERROR_BAD_CHAR_FILE		-10



# define T_REG_P1				0x1
# define T_DIR_P1				0x2
# define T_IND_P1				0x4

# define T_REG_P2				0x8
# define T_DIR_P2				0x10
# define T_IND_P2				0x20

# define T_REG_P3				0x40
# define T_DIR_P3				0x80
# define T_IND_P3				0x100

# define COMMENT_CHAR_1				'#'
# define COMMENT_CHAR_2                 ';'
# define COMMENT_CHAR_3                 '/'
# define COMMENT_CHAR_4                 '*'
# define LABEL_CHAR                     ':'
# define DIRECT_CHAR                    '%'
# define SEPARATOR_CHAR                 ','

# define LABEL_CHARS                    "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_PR	 	        "NAME_PARAM"
# define COMMENT_CMD_PR     	     	"COMMENT_PARAM"

# define NAME_CMD_STR                ".name"
# define COMMENT_CMD_STR             ".comment"
# define DEF                                     '"'
# define SEP                                     '~'
# define SPS                                     ' '





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

void				ft_manage_url(char *url);
void            ft_error_reading_file(int error);

#endif
