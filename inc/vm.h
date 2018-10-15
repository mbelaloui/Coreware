/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:22:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/15 11:34:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "./inst.h"

# define ERROR_FORMAT_FILE		1
# define ERROR_READING_FILE		2
# define ERROR_MAGIC_NUM		42
# define ERROR_SIZE_FILE		3
# define ERROR_WRONG_OPTION		6
# define ERROR_NO_PARAM			8
# define ERROR_NO_PARAM_DUMP	9
# define ERROR_NO_PARAM_ARG		10
# define ERROR_NO_PARAM_ID		11
# define ERROR_ID_CHAMP			12
# define ERROR_NO_SRC_FILE		13
# define ERROR_BAD_NBR_FILE		14
# define ERROR_NO_FILE			15

# define FORMAT_INPUT_VM		"cor"

/*
**	printing define
*/

# define MEM_SRC				0
# define MEM_DESC				1
# define MEM_LINE				64

# define PLAYER_1				1
# define PLAYER_2				2
# define PLAYER_3				3
# define PLAYER_4				4

# define COLOR_INVERS			MAX_PLAYERS * 2
# define ACTUAL_ACTION			MAX_PLAYERS * 3
# define PT_COLOR				17
# define PT_COLOR_INCERS		18
# define NULL_COLOR				0

/*
**          struct -h "aide"
** je me base sur ce aue tu as fait dans l'asm
*/

typedef struct			s_vm_option
{
	int					d;
	char				h;
	char				n;
	char				v;
}						t_vm_option;

typedef struct			s_vm_inst
{
	t_int_list			*src;
	int					size;
	struct s_vm_inst	*next;
}						t_vm_inst;

/*
** id 	 pour identifier le process pour la couleur
*/

typedef struct			s_champ
{
	int					num;
	int					id;
	char				*name;
	char				*comment;
	int					size;
	t_vm_inst			*src;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_url_file
{
	int					num;
	char				*url;
	struct s_url_file	*next;
}						t_url_file;

typedef struct			s_vm
{
	int					nbr_champ;
	int					dump;
	int					mem[MEM_SIZE][2];
	t_champ				*champs;
	int					live[MAX_PLAYERS];	// pour l'affichage
	int					id_last_a_live;		///
}						t_vm;

typedef struct			s_opr_exe
{
	int					id_opr;
	int					nbr_param;
	int					type_arg[3];
	int					size_arg[3];
	int					vale_arg[3];
}						t_opr_exe;

typedef struct			s_process
{
	int					id_parent;
	int					curent_pc;
	int					pc;
	BOOL				carry;
	int					reg[REG_NUMBER];
	int					time_to_exe;
	t_opr_exe			curent_instruction;
	int					nbr_live;
	int					color_start;
	BOOL				a_live; //tempt enlever plus tard apres avoir fait en sort de free les process mort
	struct s_process	*next;
}						t_process;

void					ft_init_vm_option(t_vm_option *op);
void					ft_put_usage_vm(void);
void					ft_display_help(void);

void					ft_init_vm(t_vm *vm, t_url_file *url_champ,
	t_vm_option op_vm);
void					ft_put_vm(t_vm *vm);
BOOL					ft_dell_vm(t_vm *vm);
void					ft_fight(t_vm *vm, t_process *list_process);

void					ft_error_reading_file(int error);
void					ft_error_param_vm(int error, char *param);

int						ft_handle_op_dump(char **tab, t_vm_option *op_vm);
int						ft_extract_vm_op(char **tab, t_vm_option *op_vm);
int						ft_search_for_op(char **tab, t_vm_option *op_vm);

BOOL					ft_manage_vm_url(char *url);
char					*ft_get_url(char **tab);
int						ft_get_value_op(char *str);
BOOL					ft_check_signature(unsigned char r[4]);
void					ft_put_oct(unsigned char r[4]);
BOOL					ft_get_next_oct(int fd, unsigned char (*tab)[4]);
void					ft_get_vm_magic(int fd);
char					*ft_get_vm_name(int fd);
int						ft_get_vm_size(int fd);
BOOL					ft_is_null(int fd);
char					*ft_get_vm_comment(int fd);
t_vm_inst				*ft_get_vm_src(int fd, t_champ *champ,
		t_op *op_tab[NBR_OP]);

int						ft_manage_p1(int desc, t_op *op, t_op *op_tab[NBR_OP]);
int						ft_manage_p2(int desc, t_op *op, t_op *op_tab[NBR_OP]);
int						ft_manage_p3(int desc, t_op *op, t_op *op_tab[NBR_OP]);
int						ft_manage_param(char *src, t_op *op,
		t_int_list **inst_src_list, t_op *op_tab[NBR_OP]);

int						ft_handle_op_n(char **tab, t_url_file **champ);
t_url_file				*ft_get_id_champ(char **tab);

t_champ					*ft_read_champ_file(int fd, int num,
		t_op*op_tab[NBR_OP], int pos);
t_champ					*ft_new_champ(int pos);
void					ft_dell_champ(t_champ **champ);
void					ft_put_champ(t_champ *champ);
void					ft_put_raw_src_champ(char *src, int size);
void					ft_put_inst_src_vm(t_vm_inst *vm_src);
int						ft_manage_opr(int opr, t_int_list **inst_src_list);
char					*ft_read_src(int fd, int size);
BOOL					ft_add_bgn_champ(t_champ *champ, t_champ **list);
BOOL					ft_add_end_champ(t_champ *champ, t_champ **list);
void					ft_put_listchamp(t_champ *list);

t_vm_inst				*ft_new_vm_inst(t_int_list *src);
BOOL					ft_add_vm_instlist(t_int_list *src, t_vm_inst **list);
int						ft_get_size_param(t_op *op_tab[NBR_OP], int id_opr,
		unsigned char arg);
t_vm_inst				*ft_str_to_list_inst(char *src, t_champ *champ,
		t_op *op_tab[NBR_OP]);

void					ft_put_url_file(t_url_file *list);
BOOL					ft_dell_urlfile(t_url_file **to_dell);
BOOL					ft_dell_bgn_urlfile(t_url_file **list);
BOOL					ft_dell_list_urllist(t_url_file **to_free);
BOOL					ft_add_urlfilelist(int num, char *url,
		t_url_file **list);
t_url_file				*ft_new_url_file(int num, char *url);
int						ft_get_prev_num_urlfile(t_url_file *list);
BOOL					ft_existe_num(int num, t_url_file *list);
int						ft_size_url_champ(t_url_file *list);

/*
** a
*/

t_process				*ft_new_process(int id_parent, int add_start);
BOOL					ft_add_process(t_process *proces, t_process **list);
t_process				*ft_init_process(t_vm vm);
void					ft_put_process(t_process *process);
void					ft_dell_list_process(t_process *list_process);
void					ft_get_next_instuction(t_opr_exe *opr_exe, t_vm *vm,
	t_process *process, t_op *op_tab[NBR_OP]);
int		ft_get_total_live(t_process *list_process);
BOOL	ft_check_survivor(t_process *list_process, t_vm *vm);

/*
** a
*/

void					ft_put_opr_exe(t_opr_exe *opr, t_op *op_tab[NBR_OP]);
int						ft_get_size_type(int id_opr, int arg,
	t_op *op_tab[NBR_OP]);
int						ft_set_size_arg(t_opr_exe *opr_exe,
	t_op *op_tab[NBR_OP]);
void					ft_set_desc_arg(int ocp, int nbr_param,
	t_opr_exe *opr_exe);
int						ft_set_vale_arg(t_vm *vm, int pc, t_opr_exe *opr);
int						ft_process_desc_ok(t_opr_exe *opr_exe,
	t_op *op_tab[NBR_OP],
	t_vm *vm, t_process *process);
int						ft_process_desc_ko(t_opr_exe *opr_exe,
	t_op *op_tab[NBR_OP], t_vm *vm, t_process *process);
void					ft_set_color_inst(t_vm *vm, int start, int len, int id_process);

void	ft_rest_color(t_vm *vm, t_process *list_process);

void	ft_init_tab_instruction(BOOL (*action_instructions[NBR_OP])(t_vm *vm, t_process *process));
BOOL	ft_null(t_vm *vm, t_process *process);
BOOL	ft_aff(t_vm *vm, t_process *process);
BOOL	ft_lfork(t_vm *vm, t_process *process);
BOOL	ft_lldi(t_vm *vm, t_process *process);
BOOL	ft_lld(t_vm *vm, t_process *process);
BOOL	ft_fork(t_vm *vm, t_process *process);
BOOL	ft_sti(t_vm *vm, t_process *process);
BOOL	ft_ldi(t_vm *vm, t_process *process);
BOOL	ft_zjmp(t_vm *vm, t_process *process);
BOOL	ft_xor(t_vm *vm, t_process *process);
BOOL	ft_or(t_vm *vm, t_process *process);
BOOL	ft_and(t_vm *vm, t_process *process);
BOOL	ft_sub(t_vm *vm, t_process *process);
BOOL	ft_add(t_vm *vm, t_process *process);
BOOL	ft_st(t_vm *vm, t_process *process);
BOOL	ft_ld(t_vm *vm, t_process *process);
BOOL	ft_live(t_vm *vm, t_process *process);
/*
** a
*/

void					ft_dump(t_vm *vm);
void					ft_put_mem(int mem[MEM_SIZE][2]);
void					ft_init_mem(t_vm *vm, t_process *list_process);
#endif
