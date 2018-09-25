/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:22:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:22:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "./inst.h"

# define ERROR_FORMAT_FILE		1
# define ERROR_READING_FILE		2
# define ERROR_MAGIC_NUM		42
# define ERROR_SIZE_FILE		3
# define ERROR_NOT_ENOUGH_MEM	4
# define ERROR_NOT_ENOUGH_PARAM	5
# define ERROR_WRONG_OPTION		6
//# define ERROR_BAD_PARAM		7
# define ERROR_NO_PARAM			8
# define ERROR_NO_PARAM_DUMP	9
# define ERROR_NO_PARAM_ARG		10
# define ERROR_NO_PARAM_ID		11
# define ERROR_ID_CHAMP			12
# define ERROR_NO_SRC_FILE		13
# define ERROR_BAD_NBR_FILE		14

# define FORMAT_INPUT_VM			"cor"

/*************************************/
/*          struct -h "aide"         */
/*************************************/
/* je me base sur ce aue tu as fait dans l'asm */

typedef struct	s_vm_option
{
	int			d; /*dump*/
	char		a; /*pas compris ahah*/
	char		h; /*help*/
	char		n; /*nb_champ*/
	char		v; /*visu*/
}				t_vm_option;

typedef struct			s_vm_inst
{
	t_int_list			*src;
	int					size;
	struct s_vm_inst	*next;
}						t_vm_inst;

typedef struct	s_champ
{
	int			id;			//c'est pour toi david
	char		*url_file;	//ca aussi c'est pour toi david !!!!
	char		*name;
	char		*comment;
	int			size;
	t_vm_inst	*src;
}				t_champ;

typedef struct		s_url_file
{
	int				id;
	char			*url;
	struct s_url_file	*next;
}					t_url_file;

typedef struct			s_listchamp
{
	t_champ				*champ;
	struct s_listchamp	*next;
}						t_listchamp;

typedef struct		s_vm
{
	t_listchamp		*champs;
	int				nbr_champ;
	int				dump;
	char			*mem;
}					t_vm;

/*option vm*/
void		ft_init_vm_option(t_vm_option *op);
void		ft_put_usage_vm(void);
void		ft_display_help(void);
/***********/

void		ft_error_reading_file(int error);
void		ft_error_exe(int error);
void		ft_error_param_vm(int error, char *param);

int			ft_handle_op_dump(char **tab, t_vm_option *op_vm);
int			ft_extract_vm_op(char **tab, t_vm_option *op_vm);
int			ft_search_for_op(char **tab, t_vm_option *op_vm);

BOOL		ft_manage_vm_url(char *url);
char		*ft_get_url(char **tab);
int				ft_get_value_op(char *str);
BOOL			ft_check_signature(unsigned char r[4]);
void			ft_put_oct(unsigned char r[4]);
BOOL			ft_get_next_oct(int fd, unsigned char (*tab)[4]);
void			ft_get_vm_magic(int fd);
char			*ft_get_vm_name(int fd);
int				ft_get_vm_size(int fd);
BOOL			ft_is_null(int fd);
char			*ft_get_vm_comment(int fd);
t_vm_inst	*ft_get_vm_src(int fd, t_champ *champ, t_op *op_tab[NBR_OP]);

int				ft_manage_p1(int desc, t_op *op, t_op *op_tab[NBR_OP]);
int				ft_manage_p2(int desc, t_op *op, t_op *op_tab[NBR_OP]);
int				ft_manage_p3(int desc, t_op *op, t_op *op_tab[NBR_OP]);
int				ft_manage_param(char *src, t_op *op, t_int_list **inst_src_list,
		t_op *op_tab[NBR_OP]);

int				ft_handle_op_n(char **tab, t_url_file **champ);
t_url_file		*ft_get_id_champ(char **tab);
/*
*/
t_champ			*ft_read_champ_file(int fd, int id,t_op*op_tab[NBR_OP]);

void			ft_dell_champ(t_champ **champ);
void			ft_put_champ(t_champ *champ);
void			ft_put_raw_src_champ(char *src, int size);
void			ft_put_inst_src_vm(t_vm_inst *vm_src);
int				ft_manage_opr(int opr, t_int_list **inst_src_list);
char			*ft_read_src(int fd, int size);
/*
*/

t_vm_inst		*ft_new_vm_inst(t_int_list *src);
BOOL			ft_add_vm_instlist(t_int_list *src, t_vm_inst **list);


int	ft_get_size_param(t_op *op_tab[NBR_OP], int id_opr, unsigned char arg);

t_vm_inst		*ft_str_to_list_inst(char *src, t_champ *champ,
		t_op *op_tab[NBR_OP]);

/*
*/
void			ft_put_url_file(t_url_file *list);
BOOL			ft_dell_urlfile(t_url_file **to_dell);
BOOL			ft_dell_bgn_urlfile(t_url_file **list);
BOOL			ft_dell_list_urllist(t_url_file **to_free);
BOOL			ft_add_urlfilelist(int id, char *url, t_url_file **list);
t_url_file		*ft_new_url_file(int id, char *url);
int				ft_get_prev_id_urlfile(t_url_file *list);
BOOL			ft_existe_id(int id, t_url_file *list);
int				ft_size_url_champ(t_url_file *list);
/*
*/
BOOL			ft_add_champ_champlist(t_champ *champ, t_listchamp **list);
t_listchamp		*ft_new_listchamp(t_champ *champ);
void			ft_put_champlist(t_listchamp *list);

#endif























