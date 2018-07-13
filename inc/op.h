/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2018/07/13 12:03:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H

# include "asm.h"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define COMMENT_CHAR_1			';'

# define COMMENT_CHAR_2			'/'
# define COMMENT_CHAR_3			'*'

# define COMMENT_STR_1			"//"
# define COMMENT_STR_2			"/*"
# define COMMENT_STR_3			"*/"


# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define NAME_CMD_PARAM			"NAME_PARAM"
# define COMMENT_CMD_STRING		".comment"
# define DELIMITEUR				'\"'

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

#define NBR_OP					17

typedef char		t_arg_type;

typedef struct		s_op
{
	int				mnemonique;		//
	char			*name;			//
	int				nbr_param;		//
	int				param;			//
	int				cycle;			//
	char			*description;	//
	BOOL			desc_param;
	int				size_label;
}					t_op;

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

t_op				*ft_new_op(int mnemonique, char *name, int nbr_param,
		int cycle);
void				ft_put_op(t_op *op_tab[NBR_OP]);
void				ft_init_op_tab(t_op *op_tab[NBR_OP]);
void				ft_set_param(t_op *op_tab[NBR_OP]);
void				ft_set_size_label(t_op *op_tab[NBR_OP]);
void				ft_set_desc_param(t_op *op_tab[NBR_OP]);
void				ft_put_op_param_3(t_op *op);
void				ft_put_op_param_2(t_op *op);
void				ft_put_op_param_1(t_op *op);
char				*ft_get_name(t_op *op_tab);
int					ft_get_cycle(t_op *op_tab);
int					ft_get_type_param(t_op *op_tab);
void				ft_put_typ_param(t_op *op_tab[NBR_OP]);
void				ft_put_size_label(t_op *op_tab[NBR_OP]);

BOOL				ft_dell_op(t_op *op_tab[NBR_OP]);
BOOL				ft_is_type_ok(t_op *op_tab, int type);
int					ft_is_name_op(char *str);

t_op				*ft_get_op(t_op *op_tab[NBR_OP], char *str);
void				ft_put_desc_param(t_op *op_tab[NBR_OP]);

#endif
