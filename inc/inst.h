/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:21:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 19:07:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INST_H
# define INST_H

# include "./op.h"

# define SIZE_INST		6

typedef struct			s_instruction
{
	char				*label;
	char				*opcode;
	int					*add;
	int					size[SIZE_INST];
	BOOL				desc;
	int					size_inst;
	int					position;
	t_charlist			*param;
}						t_inst;

typedef struct			s_list_inst
{
	t_inst				*data;
	struct s_list_inst	*next;
}						t_instlist;

t_inst					*ft_new_inst(char *label, char *op, t_charlist *args);
void					ft_put_inst(t_inst *inst);
void					ft_put_instlist(t_instlist *list);
void					ft_dell_inst(t_inst **inst);
BOOL					ft_dell_list_instlist(t_instlist **to_free);
BOOL					ft_add_end_instlist(t_inst *inst, t_instlist **list);
void					ft_handle_args_inst(char **tab_args, char *name_op,
		char *args, t_op *op);
int						ft_get_size_program(t_instlist *list);
int						ft_get_desc_args(t_charlist *param);
int						ft_get_size_bin_inst(int size[SIZE_INST]);

#endif
