/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:22:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 16:34:26 by dalauren         ###   ########.fr       */
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

typedef struct			s_vm_inst
{
	t_int_list			*src;
	int					size;
	struct s_vm_inst	*next;
}						t_vm_inst;

/*************************************/
/*          struct -h "aide"         */
/*************************************/
/* je me base sur ce aue tu as fait dans l'asm */

typedef struct	s_vm_option
{
	int			h; /*help*/
	int			n; /*nb_champ*/
	int			D; /*dump*/
	int			v; /*visu*/
	int			a; /*pas compris ahah*/
	int			dump_value; /*dump value*/
}				t_vm_option;

typedef struct	s_champ
{
	int			id;			//c'est pour toi david
	char		*url_file;	//ca aussi c'est pour toi david !!!!
	char		*name;
	char		*comment;
	int			size;
	t_vm_inst	*src;
}				t_champ;


/*option vm*/
void		ft_init_vm_option(t_vm_option *op);
/***********/

int		ft_error_reading_file(int error);
int		ft_error_exe(int error);

BOOL			ft_check_signature(unsigned char r[4]);
void			ft_put_oct(unsigned char r[4]);
BOOL			ft_get_next_oct(int fd, unsigned char (*tab)[4]);
void			ft_get_vm_magic(int fd);
char			*ft_get_vm_name(int fd);
int				ft_get_vm_size(int fd);
BOOL			ft_is_null(int fd);
char			*ft_get_vm_comment(int fd);
t_vm_inst*ft_get_vm_src(int fd, t_champ *champ, t_op *op_tab[NBR_OP]);


t_champ			*ft_read_champ_file(int fd, t_op*op_tab[NBR_OP]);

void			ft_dell_champ(t_champ **champ);
void			ft_put_champ(t_champ *champ);
void			ft_put_raw_src_champ(char *src, int size);
#endif




















