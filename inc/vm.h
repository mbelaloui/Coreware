/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:22:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/17 14:48:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "./inst.h"

# define ERROR_FORMAT_HEAD	1
# define ERROR_READING_FILE	2
# define ERROR_MAGIC_NUM	42
# define ERROR_SIZE_FILE	3


typedef struct	s_champ
{
	char		*name;
	char		*comment;
	int			size;
	//src
}				t_champ;

int     ft_error_reading_file(int error);

BOOL			ft_check_signature(unsigned char r[4]);
void			ft_put_oct(unsigned char r[4]);
BOOL			ft_get_next_oct(int fd, unsigned char (*tab)[4]);
void			ft_get_vm_magic(int fd);
char			*ft_get_vm_name(int fd);
int				ft_get_vm_size(int fd);
BOOL			ft_is_null(int fd);
char			*ft_get_vm_comment(int fd);
t_instlist		*ft_get_vm_src(int fd, int size_prog);
#endif




















