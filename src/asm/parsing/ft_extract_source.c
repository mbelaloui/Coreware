/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_source.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:06:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/05 13:08:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static BOOL			get_label(char *str, char **label)
{
	int i;

	if (ft_is_name_op(str) == -1)
	{
		i = 0;
		while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
			i++;
		*label = ft_strcut(str, 0, i);
		if (str[i])
		{
			if (str[i] == LABEL_CHAR && !str[i + 1])
				return (T);
			else
				ft_error_label(ERROR_END_CHAR_LABEL,
						*label, str[i], str);
		}
		else
			ft_error_label(ERROR_FORMAT_LABEL, *label,
					str[i], 0);
	}
	return (F);
}

static BOOL			get_op(char *str, char **op)
{
	if (ft_isempty(str))
		return (F);
	if (ft_is_name_op(str) == -1)
		ft_error_op(ERROR_OP, str);
	*op = ft_strdup(str);
	return (T);
}

static t_charlist	*get_args(char **str, char *name_op, t_op *op_tab[NBR_OP])
{
	t_charlist	*ret_args;
	char		*args;
	char		**tab_args;
	t_op		*op;

	args = NULL;

	op = ft_get_op(op_tab, name_op);
	tab_args = ft_prepare_args(str, name_op, op, &args);
	ft_check_arg_asm(tab_args, name_op, args, op);
	ft_strdel(&args);
	ret_args = ft_mat_to_charlist(tab_args);
	ft_free_mat(&tab_args);
	return (ret_args);
}

static t_inst		*quarry_line(t_charlist *sc, char *label, char *op,
		t_op *op_tab[NBR_OP])
{
	t_charlist	*list_args;
	t_inst		*inst;
	char		**args;
	int			nu;

	nu = 0;
	list_args = NULL;
	if (!ft_isempty(sc->data))
	{
		args = ft_strsplit(sc->data, SPS);
		if (get_label(args[nu], &label))
			nu++;
		if (get_op(args[nu], &op))
		{
			nu++;
			list_args = get_args(&(args[nu]), op, op_tab);
		}
		inst = ft_new_inst(label, op, list_args);
		ft_free_mat(&args);
		return (inst);
	}
	return (NULL);
}

/*
**	in put
**	{
**		sc	<A list of strings, each node contains a line of the source code>
**		player	<The structure where we will store the data of the champion>
**		op_tab	<the table that contains the information about the instructions>
**	}
**
**	what the fonction do ??
**	this function check each line of code and handles the different variables
**	of an instruction, it will do the syntaxique and the semantique teste part,
**	and save the source code in a simpler format to use later.
**	{
**		1 - {label}
**		2 - {instruction [argument]}
**		3 - {label}	{instruction [argument]}
**
**		the value with "OK" will be saved in this part
**		typedef struct			s_instruction
**		{
**			char				*label;
**			char				*opcode;
**			int					*add;
**			int					size[SIZE_INST];	OK
**			BOOL				desc;
**			int					size_inst;			OK
**			int					position;			OK
**			t_charlist			*param;				OK
**		}						t_inst;
**
**	}
**
**	output
**	{
**		we add intruction of the champion to the struct player
**	}
*/

void				ft_extraire_source(t_charlist *sc, t_player *player,
		t_op *op_tab[NBR_OP])
{
	t_instlist	*src;
	t_inst		*inst;
	int			add_inst;
	char		*label;
	char		*op;

	add_inst = 0;
	src = NULL;
	op = NULL;
	label = NULL;
	while (sc)
	{
		if (!ft_isempty(sc->data))
		{
			inst = quarry_line(sc, label, op, op_tab);
			if (inst == NULL)
				ft_error_inst(ERROR_INSTRUCTION);
			ft_get_size_inst(inst, op_tab);
			inst->position = add_inst;
			add_inst += inst->size_inst;
			ft_add_end_instlist(inst, &src);
		}
		sc = sc->next;
	}
	player->src = src;
}
