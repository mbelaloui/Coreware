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

void				ft_manage_url(char *url);
void            ft_error_reading_file(int error);

#endif
