/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:55:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/19 19:53:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/inc/libft.h"
# include "../libft/inc/option.h"
# include "op.h"
# include "./inst.h"

# define ERROR_NO_PARAM				-1
# define ERROR_MULTIPUL_PARAM		-2
# define ERROR_WRONG_FORMAT_FILE	-3
# define ERROR_READING_FILE			-4
# define ERROR_HEAD_NAME			-5
# define ERROR_HEAD_COMMENT			-6
# define ERROR_FORMAT_NAME			-7
# define ERROR_FORMAT_COMMENT		-8
# define ERROR_EMPTY_FILE			-9
# define ERROR_BAD_CHAR_FILE		-10
# define ERROR_END_CHAR_LABEL		-11
# define ERROR_FORMAT_LABEL			-12
# define ERROR_OP					-13
# define ERROR_FORMAT_LABEL_ARG		-14
# define ERROR_ARG_NULL				-15
# define ERROR_NBR_ARG				-16
# define ERROR_FORMAT_ARG			-17
# define ERROR_BAD_ARG				-18
# define ERROR_TYPE_ARG				-18
# define ERROR_INSTRUCTION			-19
# define ERROR_LABEL_NOT_DECLARED	-20
# define ERROR_LEN_NAME				-21
# define ERROR_LEN_COMMENT			-22
# define WARNING_SIZE_CHAMP			-23
# define WARNING_DOUBLE_DEF_LAB		-24
# define WARNING_UNUSED_LAB			-25
# define ERROR_UNKNOWN_ARG			-26

# define IND_REF					255255
# define DIR_REF					255255255255

# define COMMENT_CHAR_1				'#'
# define COMMENT_CHAR_2				';'
# define COMMENT_CHAR_3				'/'
# define COMMENT_CHAR_4				'*'
# define LABEL_CHAR					':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR				','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_PR				"NAME_PARAM"
# define COMMENT_CMD_PR			 	"COMMENT_PARAM"

# define NAME_CMD_STR				".name"
# define COMMENT_CMD_STR			".comment"
# define DEF						'"'
# define SEP						'~'
# define RET						'\n'
# define SPS						' '
# define REGISTRE_CHAR				'r'

# define FORMAT_INPUT				"s"
# define FORMAT_OUTPUT				".cor"
//# define SIZE_INST					6

# define LABL						0
# define OPPR						1
# define DESC						2
# define ARG1						3
# define ARG2						4
# define ARG3						5
/*
typedef	struct				s_instruction
{
	char					*label;
	char					*opcode;
	int						*add;
	int						size[SIZE_INST];
	BOOL					desc;
	int						size_inst;
	int						position;
	t_charlist				*param;
}							t_inst;

typedef	struct				s_list_inst
{
	t_inst					*data;
	struct s_list_inst		*next;
}							t_instlist;
*/
typedef struct				s_symbole
{
	char					*data;
	int						add;
	BOOL					used;
	struct s_symbole		*next;
}							t_symbole;

typedef struct				s_player
{
	char					*name;
	char					*description;
	char					*url_output;
	t_instlist				*src;
}							t_player;

typedef struct				s_champ
{
	char					*name;
	char					*description;
	char					*add;
	t_instlist				*src;
}							t_champ;

/*
*/

void			ft_error_label(int error, char *label, char c, char *str);
void			ft_error_reading_file(int error);
void			ft_error_param(int error, char *param);
void			ft_error_op(int error, char *str);
void			ft_error_head(int error, char *str_file);
void			ft_error_inst(int error);
void			ft_error_args(int error, char *op, char *args, char *arg);
void			ft_error_option(int id_error, char *name, t_option *op,
		char c);
char			*ft_manage_url(char *url);
void			ft_set_asm_options(char c, t_option *options);
BOOL			ft_extract_asm_options(char *param, t_option *op, char *name);
void			ft_init_asm_option(t_option *op);

/*
*/
/*
t_inst			*ft_new_inst(char *label, char *op, t_charlist *args);
void			ft_put_inst(t_inst *inst);
void			ft_put_instlist(t_instlist *list);
void			ft_dell_inst(t_inst **inst);
BOOL			ft_dell_list_instlist(t_instlist **to_free);
BOOL			ft_add_end_instlist(t_inst *inst, t_instlist **list);
void			ft_handle_args_inst(char **tab_args, char *name_op, char *args, t_op *op);
int				ft_get_size_program(t_instlist *list);
int				ft_get_desc_args(t_charlist *param);
int				ft_get_size_bin_inst(int size[SIZE_INST]);
*///unsigned int	*ft_int_to_byts(int val, int size);

/*
*/

void			ft_warning(int id_warn, int size, char *data, t_option *op);
void			ft_put_player(t_player *player);
void			ft_put_bin_source(t_player *player);
void			ft_put_decimal_source(t_player *player);
void			ft_put_hexa_source(t_player *player);
void			ft_get_arg_translat(t_inst *inst, t_symbole *symbole,
		int *add, int i);
void			ft_translate_player(t_player *player, t_op *op_tab[NBR_OP],
		t_option *op);
void			ft_put_usage(char *name, t_option *op);
void			ft_put_option(t_option *option);
void			ft_put_help(char *name, t_option *op);

/*
*/

void			ft_free_player(t_player *player);
void			ft_put_head(t_player *player, int fd);
void			ft_put_bynary(int data, int size, int fd);
BOOL			ft_extract_info_player(t_charlist *file, t_player *player	, t_op *op_tab[NBR_OP]);
void			ft_put_src(t_player *player, int fd);
void			ft_make_out_put(t_player *player);
char			**ft_prepare_args(char **str, char *name_op, t_op *op, char **args);

/*
*/

char			*ft_extract_simpl_comment(char *file);
char			*ft_extract_ml_comment(char *file);
t_charlist		*ft_clean_file(t_charlist *file);
int				ft_skip_spaces(char *str_file);
int				ft_get_index_end(char *str_file);
int				ft_get_data(char *str, char **data);
int				ft_extraire_head_info(char *str_file, t_player *player);
BOOL			ft_is_label(char *str);
BOOL			ft_is_direct(char *arg);
BOOL			ft_is_indirect(char *arg);
BOOL			ft_is_register(char *arg);
int				ft_get_type_args(char *arg, int pos);
void			ft_extraire_source(t_charlist *sc, t_player *player,
		t_op *op_tab[NBR_OP]);
BOOL			ft_is_option(const char option);
void			ft_set_options(char c, t_option *options);

/*
*/

void			ft_get_size_inst(t_inst *inst, t_op *op_tab[NBR_OP]);

/*
 */

t_symbole		*ft_new_symbole(char *sym, int add);
int				ft_is_in_symbole(char *symbole, t_symbole *list);
BOOL			ft_add_symbole(char *data, int add, t_symbole **list,
		t_option *op);
BOOL			ft_dell_symbole(t_symbole **to_free);
BOOL			ft_dell_list_symbole(t_symbole **to_free);
void			ft_put_list_symbole(t_symbole *list);
t_symbole		*ft_init_symbole_tab(t_player *player, t_option *op);

/*
*/

void			ft_set_used_label(char *symbole, t_symbole *list);
void			ft_check_for_label(t_symbole *symbole, t_instlist *src, t_option *op);
#endif
