#include "../../inc/asm.h"
#include "../../libft/inc/option.h"

/*****************************************************************/
		//ft_get_size_program.c
/*****************************************************************/
/*int	ft_get_size_program(t_instlist *list)
{
	int size_program;

	size_program = 0;
	while (list)
	{
		size_program += list->data->size_inst;
		list = list->next;
	}
	return (size_program);
}
*/
/*****************************************************************/
		//ft_extract_source.c
/*****************************************************************/
BOOL	get_label(char *str, char **label)
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

BOOL	get_op(char *str, char **op)
{
	if (ft_isempty(str))
		return (F);
	if (ft_is_name_op(str) == -1)
		ft_error_op(ERROR_OP, str);
	*op = ft_strdup(str);
	return (T);
}

t_charlist	*get_args(char **str, char *name_op, t_op *op_tab[NBR_OP])
{
	char *args;
	char **tab_args;
	t_op *op;
	t_charlist *ret_args;

	args = NULL;
	op = ft_get_op(op_tab, name_op);
	tab_args = ft_prepare_args(str, name_op, op, &args);
	ft_handle_args_inst(tab_args, name_op, args, op);
	ft_strdel(&args);
	ret_args = ft_mat_to_charlist(tab_args);
	ft_free_mat(&tab_args);
	return (ret_args);
}

t_inst	*quarry_line(t_charlist *sc,char *label, char *op, t_op *op_tab[NBR_OP])
{
	char **args;
	int nu;
	t_inst *inst;
	t_charlist *list_args;

	nu = 0;
	list_args = NULL;
	if (!ft_isempty(sc->data))
	{
		args = ft_strsplit(sc->data, SPS);
		if (get_label(args[nu], &label))
			nu++;
		if(get_op(args[nu], &op))
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

void	ft_extraire_source(t_charlist *sc, t_player *player,
t_op *op_tab[NBR_OP])
{
	char *label;
	char *op;
	t_instlist *src;
	t_inst *inst;
	int	add_inst;

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

/*****************************************************************/
		//ft_extract_info.c
/*****************************************************************/
BOOL	ft_extract_info(t_charlist *file, t_player *player, t_op *op_tab[NBR_OP])
{
	char *str_file;
	int pt;
	char *str;

	if (!(str_file = ft_charlist_to_str(file, SEP)))
		return (F);
	pt = ft_extraire_head_info(str_file, player);
	str = ft_format_str(str_file+pt);
	ft_strdel(&str_file);
	t_charlist *sc = ft_str_to_format_charlist(str, SEP);
	ft_extraire_source(sc, player, op_tab);
	ft_dell_list_charlist(&sc);
	ft_strdel(&str);
	return (T);
}

/*****************************************************************/
		//ft_new_symbole.c
/*****************************************************************/
t_symbole	*ft_new_symbole(char *sym, int add)
{
	t_symbole *ret;

	ret = malloc(sizeof(*ret));
	ret->data = ft_strdup(sym);
	ret->add = add;
	ret->used = F;
	ret->next = NULL;
	return (ret);
}

/*****************************************************************/
		//ft_is_in_symbole.c
/*****************************************************************/
int	ft_is_in_symbole(char *symbole, t_symbole *list)
{
	while (list)
	{
		if (!ft_strcmp(list->data, symbole))
			return (list->add);
		list = list->next;
	}
	return (-1);
}

/*****************************************************************/
		//ft_add_symbole.c
/*****************************************************************/
BOOL    ft_add_symbole(char *data, int add, t_symbole **list, t_option *op)
{
	t_symbole      *temp_node;
	t_symbole      *pt_list;

	if (!(temp_node = ft_new_symbole(data, add)))
		return (F);
	if ( ft_is_in_symbole(data, *list) > -1)
		ft_warning(WARNING_DOUBLE_DEF_LAB, 0, data, op);
	if (!(*list))
		*list = temp_node;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp_node;
	}
	return (T);
}

/*****************************************************************/
		//ft_dell_symbole.c
/*****************************************************************/
BOOL    ft_dell_symbole(t_symbole **to_free)
{
	if (to_free && *to_free)
	{
		ft_strdel(&(*to_free)->data);
		free(*to_free);
		*to_free = NULL;
		return (T);
	}
	return (F);
}

/*****************************************************************/
		//ft_dell_list_symbole.c
/*****************************************************************/
BOOL    ft_dell_list_symbole(t_symbole **to_free)
{
	t_symbole *pt;

	if (!to_free || !(*to_free))
		return (F);
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		*to_free = (*to_free)->next;
		ft_dell_symbole(&pt);
	}
	*to_free = NULL;
	return (T);
}

/*****************************************************************/
		//ft_put_list_symbole.c
/*****************************************************************/
void	ft_put_list_symbole(t_symbole *list)
{
	ft_printf("|\t-----\t\t|\t-------\t|\t-----\t|\n");
	ft_printf("|\tlabel\t\t|\taddress\t|\tused\t|\n");
	ft_printf("|\t-----\t\t|\t-------\t|\t-----\t|\n");
	while (list)
	{
		ft_printf("|\t%s\t\t|\t%d\t|\t %s\t|\n",
		list->data, list->add, (list->used) ? "yes" : "no");
		list = list->next;
	}
	ft_printf("|\t-----\t\t|\t-------\t|\t-----\t|\n");
}

/*****************************************************************/
		//ft_set_used_label.c
/*****************************************************************/
void	ft_set_used_label(char *symbole, t_symbole *list)
{
	while (list)
	{
		if (!ft_strcmp(list->data, symbole))
		{
			list->used = T;
			return ;
		}
		list = list->next;
	}
}

/*****************************************************************/
		//ft_check_for_label.c
/*****************************************************************/
void	handel_indirect_label(char *arg, t_symbole *symbole)
{
	if (ft_is_in_symbole(arg, symbole) > -1)
		ft_set_used_label(arg , symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg , 0, NULL);
}

void	handel_direct_label(char *arg, t_symbole *symbole)
{
	if (ft_is_in_symbole(arg, symbole) >-1)
		ft_set_used_label(arg, symbole);
	else
		ft_error_label(ERROR_LABEL_NOT_DECLARED, arg , 0, NULL);
}

void	check_symbole_tab(t_symbole *symbole, t_option *op)
{
	while (symbole)
	{
		if (!symbole->used)
			ft_warning(WARNING_UNUSED_LAB, 0, symbole->data, op);
		symbole = symbole->next;
	}
}

void	ft_check_for_label(t_symbole *symbole, t_instlist *src, t_option *op)
{
	char *arg;
	t_charlist *args;
	t_instlist *pt;

	pt = src;
	while (pt)
	{
		args = pt->data->param;
		while (args)
		{
			arg = args->data;
			if (arg[0] == LABEL_CHAR && ft_is_label(arg + 1))
				handel_indirect_label(arg + 1, symbole);
			if  (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR
				&& ft_is_label(arg + 2))
				handel_direct_label(arg + 2, symbole);
			args = args->next;
		}
		pt = pt->next;
	}
	check_symbole_tab(symbole, op);
}

/*****************************************************************/
		//ft_get_desc_args.c
/*****************************************************************/
int		get_desc_arg(char *arg)
{
	if (!arg)
		return (0);
	if (ft_is_direct(arg))
		return (DESC_DIR);
	if (ft_is_indirect(arg))
		return (DESC_IND);
	if (ft_is_register(arg))
		return (DESC_REG);

		return (0);
}

int		ft_get_desc_args(t_charlist *param)
{
	t_charlist *pt;
	int desc;
	char *arg1;
	char *arg2;

	arg1 = NULL;
	arg2 = NULL;
	desc = 0;
	pt = param;
	arg1 = pt->data;//voir plus en detaille cette inst
	if (pt->next)
	{
		pt = pt->next;
		arg2 = pt->data;
		if (pt->next)
		{
			pt = pt->next;
			desc = desc | get_desc_arg(pt->data);
		}
		desc = desc >> 2 | get_desc_arg(arg2);
	}
	desc = desc >> 2 | get_desc_arg(arg1);
	return (desc);
}

/*****************************************************************/
		//ft_get_size_bin_inst.c
/*****************************************************************/
int	ft_get_size_bin_inst(int size[SIZE_INST])
{
	int i;
	int somme;
	
	i = 0;
	somme = 0;
	while (i < SIZE_INST)
	{
		if (size[i] != -1)
			somme += size[i];
		i++;
	}
	return (somme);
}

/*****************************************************************/
		//ft_int_to_byts.c
/*****************************************************************/
unsigned int     *ft_int_to_byts(int val, int size)
{
	unsigned int *ret;

	if (!(ret = malloc(sizeof(int) * size)))
		return (NULL);
	if (size == DIR_SIZE)
	{
		ret[3] = (((unsigned int)val) << 24) >> 24;
		ret[2] = (((unsigned int)val) << 16) >> 24;
		ret[1] = (((unsigned int)val) << 8) >> 24;
		ret[0] = ((unsigned int)val) >> 24;
	}
	else if (size == IND_SIZE)
	{
		ret[1] = ((unsigned int)val << 24) >> 24;
		ret[0] = (((unsigned int)val) << 16) >> 24;
	}
	else if (size == REG_SIZE)
		ret[0] = ((unsigned int)val);
	else 
		ret = NULL;
	return (ret);
}

/*****************************************************************/
		//ft_init_symbole_tab.c
/*****************************************************************/
t_symbole	*ft_init_symbole_tab(t_player *player, t_option *op)
{
	t_instlist *sc;
	t_symbole *symbole;
	int add;

	add = 0;
	symbole = NULL;
	sc = player->src;
	while (sc)
	{
		if (sc->data->label)
			ft_add_symbole(sc->data->label, add, &symbole, op);
		add += sc->data->size_inst;
		sc = sc->next;
	}
	return (symbole);
}

/*****************************************************************/
		//ft_get_arg_translat.c
/*****************************************************************/

int	get_direct(t_inst *inst, char *dir, t_symbole *symbole)
{
	int add_label;

	if ((add_label = ft_is_in_symbole(dir + 1, symbole)) >-1)
		return (add_label - inst->position);
	else
		return (ft_atoi(dir));
}

int	get_indirect(t_inst *inst, char *ind, t_symbole *symbole)
{
	int add_label;

	if ((add_label = ft_is_in_symbole(ind + 1, symbole)) >-1)
		return (add_label - inst->position);
	else 
		return (ft_atoi(ind));
}

void	ft_get_arg_translat(t_inst *inst, t_symbole *symbole, int *add, int i)
{
	intmax_t add_out;
	t_charlist *pt;

	pt = inst->param;
	while (pt)
	{
		if (ft_is_direct(pt->data))
			add_out = get_direct(inst, pt->data + 1, symbole);
		else if (ft_is_indirect(pt->data))
			add_out = get_indirect(inst, pt->data, symbole);
		else if (ft_is_register(pt->data))
			add_out = ft_atoi(pt->data + 1);
		add[i++] = add_out;
		pt = pt->next;
	}
}

/*****************************************************************/
		//ft_put_source_bin.c
/*****************************************************************/
void	put_bin_delim(int i, BOOL with)
{
	int del;

	del = (with) ? 5 : 6;
	
	while (i < del)
	{
		ft_printf("   \t\t\t    -\t\t\t  |");
		i++;
	}
}

void	put_bin_source_bis1(int i, t_inst *data)
{
	int size;
	unsigned int *ret;
	t_charlist *arg;

	arg = data->param;
	while (arg)
	{
		size = data->size[i];
		ret = ft_int_to_byts(data->add[i - 2], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%8.8b{eoc}]\t    |", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%8.8b{eoc}] [{red}%8.8b{eoc}]\t"
			"    |", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}]"
			" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}] |"
				,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_bin_delim(i, F);
}

void	put_bin_source_bis2(int i, t_inst *data)
{
	t_charlist *arg;
	int size;
	unsigned int *ret;
	
	arg = data->param;
	while (arg)
	{
		size = data->size[i + 1];
		ret = ft_int_to_byts(data->add[i], size);
		if (size == REG_SIZE)
			ft_printf("\t\t\t[{green}%8.8b{eoc}]\t\t  |",ret[0]);
		else if (size == IND_SIZE)
			ft_printf("\t\t  [{red}%8.8b{eoc}] [{red}%8.8b{eoc}]\t"
			"\t  |",ret[0],ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}]"
			" [{blue}%8.8b{eoc}][{blue}%8.8b{eoc}] |"
				,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_bin_delim(i, T);
}

void	put_bin_data(t_player *player)
{
	t_instlist *pt;
	int i;

	pt = player->src;
	while (pt && !(i = 0))
	{
		if (pt->data->opcode)
		{
			ft_printf("| %8.8b |", pt->data->add[i++]);
			if (pt->data->size[DESC] == -1)
			{
				ft_printf("\t -    |");	
				put_bin_source_bis1(i + 2, pt->data);
			}
			else
			{
				ft_printf(" %8.8b |", pt->data->add[i++]);
				put_bin_source_bis2(i, pt->data);
			}
			ft_printf("\n");
		}
		pt = pt->next;
	}
}

void	ft_put_bin_source(t_player *player)
{
	ft_printf("    _____\t___\t\t\t  ____\t\t\t\t\t\t   ____ \t\t\t\t\t"
	"   ____\n");
	ft_printf("\n|   code   |    ocp   |\t\t\t  arg1\t\t\t  |\t\t\t   arg2"
	"\t\t\t  |\t\t\t   arg3\t\t\t  |\n");
	ft_printf("    ---- \t---\t \t\t  ----\t     \t\t\t\t\t   ---- \t\t\t"
	"\t\t   ----\n");
	put_bin_data(player);
	ft_printf("    ---- \t---\t \t\t  ----\t     \t\t\t\t\t   ---- \t\t\t"
	"\t\t   ----\n");
}


/*****************************************************************/
		//ft_put_source_decimal.c
/*****************************************************************/
void	put_decimal_delim(int i, BOOL with)
{
	int del;

	del = (with) ? 5 : 6;
	
	while (i < del)
	{
		ft_printf("\t    -\t\t |");
		i++;
	}
}

void	put_decimal_source_bis1(int i, t_inst *data)
{
	int size;
	unsigned int *ret;
	t_charlist *arg;

	arg = data->param;
	while (arg)
	{
		size = data->size[i];
		ret = ft_int_to_byts(data->add[i - 2], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%.3d{eoc}]\t |", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.3d{eoc}] [{red}%.3d{eoc}]\t"
			"    |", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%.3d{eoc}][{blue}%.3d{eoc}]"
			" [{blue}%.3d{eoc}][{blue}%.3d{eoc}] |"
				,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_decimal_delim(i, F);
}

void	put_decimal_source_bis2(int i, t_inst *data)
{
	t_charlist *arg;
	int size;
	unsigned int *ret;
	
	arg = data->param;
	while (arg)
	{
		size = data->size[i + 1];
		ret = ft_int_to_byts(data->add[i], size);
		if (size == REG_SIZE)
			ft_printf("\t   [{green}%.3d{eoc}]\t |",ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.3d{eoc}] [{red}%.3d{eoc}]\t"
			" |",ret[0],ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%.3d{eoc}][{blue}%.3d{eoc}]"
			" [{blue}%.3d{eoc}][{blue}%.3d{eoc}] |"
				,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_decimal_delim(i, T);
}

void	put_data_decimal(t_player *player)
{
	t_instlist *pt;
	int i;

	pt = player->src;
	while (pt && !(i = 0))
	{
		if (pt->data->opcode)
		{
			ft_printf("| %.2d\t| ", pt->data->add[i++]);
			if (pt->data->size[DESC] == -1)
			{
				ft_printf("  -    |");	
				put_decimal_source_bis1(i + 2, pt->data);
			}
			else
			{
				ft_printf(" %.3d   |", pt->data->add[i++]);
				put_decimal_source_bis2(i, pt->data);
			}
			ft_printf("\n");
		}
		pt = pt->next;
	}
}

void	ft_put_decimal_source(t_player *player)
{
	ft_printf(" _____ \t  ______\t   ____\t\t\t   ____\t\t\t   ____\n");
	ft_printf("\n| code \t|  ocp \t |\t   arg1\t\t |\t   arg2\t\t |\t   targ3"
	"\t |\n");
	ft_printf("  ---- \t   ----\t\t   ----\t     \t\t   ----\t     \t\t   ----\n");
	put_data_decimal(player);
	ft_printf("  ---- \t   ----\t\t   ----\t     \t\t   ----\t     \t\t   ----\n");
}


/*****************************************************************/
		//ft_put_source_hexa.c
/*****************************************************************/
void	put_hexa_delim(int i, BOOL with)
{
	int del;

	del = (with) ? 5 : 6;
	
	while (i < del)
	{
		ft_printf("   \t  -  \t    |");
		i++;
	}
}

void	put_hexa_source_bis1(int i, t_inst *data)
{
	int size;
	unsigned int *ret;
	t_charlist *arg;

	arg = data->param;
	while (arg)
	{
		size = data->size[i];
		ret = ft_int_to_byts(data->add[i - 2], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%.2hx{eoc}]\t    | ", ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.2hx{eoc}] [{red}%.2hx{eoc}]\t"
			"    | ", ret[0], ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%.2hx{eoc}][{blue}%.2hx{eoc}]"
			" [{blue}%.2hx{eoc}][{blue}%.2hx{eoc}] | "
				,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_hexa_delim(i, F);
}

void	put_hexa_source_bis2(int i, t_inst *data)
{
	t_charlist *arg;
	int size;
	unsigned int *ret;
	
	arg = data->param;
	while (arg)
	{
		size = data->size[i + 1];
		ret = ft_int_to_byts(data->add[i], size);
		if (size == REG_SIZE)
			ft_printf("\t[{green}%.2hx{eoc}]\t    | \t",ret[0]);
		else if (size == IND_SIZE)
			ft_printf("     [{red}%.2hx{eoc}] [{red}%.2hx{eoc}]\t"
			"    |\t",ret[0],ret[1]);
		else if (size == DIR_SIZE)
			ft_printf(" [{blue}%.2hx{eoc}][{blue}%.2hx{eoc}]"
			" [{blue}%.2hx{eoc}][{blue}%.2hx{eoc}] |\t"
				,ret[0],ret[1],ret[2],ret[3]);
		free(ret);
		i++;
		arg = arg->next;
	}
	put_hexa_delim(i, T);
}

void	put_hexa_data(t_player *player)
{
	t_instlist *pt;
	int i;

	pt = player->src;
	while (pt && !(i = 0))
	{
		if (pt->data->opcode)
		{
			ft_printf("| %.2x\t| ", pt->data->add[i++]);
			if (pt->data->size[DESC] == -1)
			{
				ft_printf("  -   |");	
				put_hexa_source_bis1(i + 2, pt->data);
			}
			else
			{
				ft_printf(" %x   |", pt->data->add[i++]);
				put_hexa_source_bis2(i, pt->data);
			}
			ft_printf("\n");
		}
		pt = pt->next;
	}
}

void	ft_put_hexa_source(t_player *player)
{
	ft_printf(" _____ \t ______\t \t____\t     \t\t____\t     \t\t____\n");
	ft_printf("\n| code \t|  ocp \t|\targ1\t    |\t\targ2\t    |\t\targ3\t"
	"    |\n");
	ft_printf("  ---- \t   ----\t \t----\t     \t\t----\t     \t\t----\n");
	put_hexa_data(player);
	ft_printf("  ---- \t   ----\t \t----\t     \t\t----\t     \t\t----\n");
}

/*****************************************************************/
		//ft_translate.c
/*****************************************************************/
void	set_data(t_inst *inst, t_op *op_tab[NBR_OP], t_symbole *symbole)
{
	t_op *op;
	int desc;
	int i;

	i = 0;
	desc = 0;
	inst->add = malloc(sizeof(int) * inst->size_inst);
	op = ft_get_op(op_tab, inst->opcode);
	inst->add[i++] = op->mnemonique;
	if (inst->size[DESC] != -1)
	{
		desc = ft_get_desc_args(inst->param);
		inst->add[i++] = desc;
	}
	ft_get_arg_translat(inst, symbole, inst->add, i);
}

void	run_translate(t_instlist *src, t_op *op_tab[NBR_OP], t_symbole *symbole)
{
	t_instlist *pt;

	pt = src;
	while (pt)
	{
		if (pt->data->opcode)
		{
			ft_get_size_bin_inst(pt->data->size);
			set_data(pt->data, op_tab, symbole);
		}
		pt = pt->next;
	}
}

void	ft_translate(t_player *player, t_op *op_tab[NBR_OP], t_option *op)
{
	t_symbole *symbole;

	symbole = ft_init_symbole_tab(player, op);
	ft_check_for_label(symbole, player->src, op);
	run_translate(player->src, op_tab, symbole);
	if (op->s)
		ft_put_list_symbole(symbole);
	ft_dell_list_symbole(&symbole);
}
/*****************************************************************/
		//ft_put_head.c
/*****************************************************************/

void	put_bynary(int data, int size, int fd)
{
	unsigned int *ret;

	ret = ft_int_to_byts(data, size);
	if (size == REG_SIZE)
	{
		write(fd,&ret[0] , 1);
	}
	else if (size == IND_SIZE)
	{
		write(fd,&ret[0] , 1);
		write(fd,&ret[1] , 1);
	}
	else if (size == DIR_SIZE)
	{
		write(fd,&ret[0] , 1);
		write(fd,&ret[1] , 1);
		write(fd,&ret[2] , 1);
		write(fd,&ret[3] , 1);
	}
	free(ret);
}

void	put_name(t_player *player, int fd)
{
	char *str;

	str = ft_strnew(PROG_NAME_LENGTH);
	ft_strlcat(str, player->name, ft_strlen(player->name) + 1);
	write(fd, str , PROG_NAME_LENGTH);
	ft_strdel(&str);
}

void	put_size(t_player *player, int fd)
{
	int i;
	unsigned int     *ret;

	ret = ft_int_to_byts(ft_get_size_program(player->src), 4);
	i = 0;
	while (i < 4)
	{
		write(fd,&ret[i] , 1);
		i++;
	}
	free(ret);
}

void	put_comment(t_player *player, int fd)
{
	char *str;
	
	str = ft_strnew(PROG_COMMENT_LENGTH);
	ft_strlcat(str, player->description,
	ft_strlen(player->description) + 1);
	write(fd, str , PROG_COMMENT_LENGTH);
	ft_strdel(&str);
}

void	ft_put_head(t_player *player, int fd)
{
	put_bynary(COREWAR_EXEC_MAGIC, 4, fd);
	put_name(player, fd);
	put_bynary(0, 4, fd);
	put_size(player, fd);
	put_comment(player, fd);
	put_bynary(0, 4, fd);
}


/*****************************************************************/
		//ft_put_src.c
/*****************************************************************/
void	put_binary_args(t_inst *inst, int fd)
{
	t_charlist *arg;
	int y;
	int i;

	arg = inst->param;
	i = 1;
	put_bynary(inst->add[i], inst->size[DESC], fd);
	i++;
	y = 0;
	while (arg)
	{
		put_bynary(inst->add[i], inst->size[ARG1 + y], fd);
		i++;
		y++;
		arg =arg->next;
	}
}

void	ft_put_src(t_player *player, int fd)
{
	t_instlist *pt;
	int i;

	pt = player->src;
	while (pt)
	{
		i = 0;
		if (pt->data->opcode)
		{
			put_bynary(pt->data->add[i],
			pt->data->size[OPPR], fd);
			if (pt->data->size[DESC] == -1)
				put_bynary(pt->data->add[1],
				pt->data->size[ARG1], fd);
			else
				put_binary_args(pt->data,fd);
		}
		pt = pt->next;
	}
}

/*****************************************************************/
		//ft_make_out_put.c
/*****************************************************************/
void	ft_make_out_put(t_player *player)
{
	int fd;
	
	fd = open(player->url_output,  O_WRONLY | O_CREAT, 777);
	ft_put_head(player, fd);
	ft_put_src(player, fd);
	ft_printf("%s {green}successfully created{eoc}\n", player->url_output);
}

/*****************************************************************/
		//option
/*****************************************************************/
BOOL	is_option_valide(char *param)
{
	if (param)
	{
		if (param[0] == '-' && ft_isalpha(param[1])
			&& (!param[2] || ft_isblank(param[2])))
			return (T);
	}
	return (F);
}

/*****************************************************************/
		//ft_is_option.c
/*****************************************************************/
BOOL     ft_is_option(const char option)
{
        if (option == 'B' || option == 'D' || option == 'h'
		|| option == 'd' || option == 'e' || option == 'H' || option == 'o'
		|| option == 'p'
		|| option == 't'  || option == 's' || option == 'S'
		|| option == 'u')
		return (T);
	return (F);
}

/*****************************************************************/
		//ft_set_option.c
/*****************************************************************/
void     ft_set_options(char c, t_option *options)
{
	if (c == 'B')
		options->B = 1;
	else if (c == 'D')
		options->D = 1;
	else if (c == 'd')
		options->d = 1;
	else if (c == 'e')
		options->e = 1;
	else if (c == 'h')
		options->h = 1;
	else if (c == 'H')
		options->H = 1;
	else if (c == 'o')
		options->o = 1;
	else if (c == 'p')
		options->p = 1;
	else if (c == 's')
		options->s = 1;
	else if (c == 'S')
		options->S = 1;
	else if (c == 'u')
		options->u = 1;
	else if (c == 't')
		options->t = 1;
}
/*****************************************************************/
		//ft_put_usage();
/*****************************************************************/
void	ft_put_usage(char *name, t_option *op)
{
	ft_printf("Usage :%s [-BDdehHopsStu] <source-file.s>.\n", name);
	if (!op->h)
		ft_printf("NB : for more informations "
		"please use <%s -h>.\n", name);
	exit(0);	
}


/*****************************************************************/
		//ft_put_option.c
/*****************************************************************/
void	ft_put_option(t_option *option)
{
	ft_printf(" B = [%s]  \n", (option->B) ? "ok" : "--");	
	ft_printf(" D = [%s]  \n", (option->D) ? "ok" : "--");	
	ft_printf(" h = [%s]  \n", (option->h) ? "ok" : "--");	
	ft_printf(" H = [%s]  \n", (option->H) ? "ok" : "--");	
	ft_printf(" o = [%s]  \n", (option->o) ? "ok" : "--");	
	ft_printf(" p = [%s]  \n", (option->p) ? "ok" : "--");	
	ft_printf(" s = [%s]  \n", (option->s) ? "ok" : "--");	
	ft_printf(" u = [%s]  \n", (option->u) ? "ok" : "--");	
}

/*****************************************************************/
		//ft_error_option.c
/*****************************************************************/
void	ft_error_option(int id_error, char *name, t_option *op, char c)
{
	ft_printf("{red}Error{eoc} parameters arguments : unknown argument [%c].\n",
	c);
	ft_put_usage(name, op);
	exit(id_error);
}


/*****************************************************************/
		//ft_extract_option.c
/*****************************************************************/
BOOL            ft_extract_options(char *param, t_option *op, char *name)
{
	int index;

	index = 0;
	while (param[index])
	{
		if (param[index] == '-')
		{
			index++;
			if (ft_is_option(param[index]) && (param[index + 1] == ' '
				|| !ft_isalpha(param[index + 1])))
				ft_set_options(param[index++], op);
			else
				ft_error_option(ERROR_UNKNOWN_ARG, name,
				op, param[index]);
		}
		else if (ft_isblank(param[index]))
			index++;
		else
			break;
	}
	return (index);
}


/*****************************************************************/
		//ft_init_option.c
/*****************************************************************/
void    ft_init_option(t_option *op)
{
	op->B = 0;
	op->d = 0;
	op->D = 0;
	op->e = 0;
	op->h = 0;
	op->H = 0;
	op->o = 0;
	op->p = 0;
	op->s = 0;
	op->S = 0;
	op->u = 0;
	op->t = 0;
}

/*****************************************************************/
		//ft_char_to_str.c
/*****************************************************************/
char	*ft_char_to_str(char c)
{
	char *ret;

	if (!ft_isprint(c) || !(ret = ft_strnew(1)))
		return (NULL);
	ret[0] = c;
	return (ret);
}

/*****************************************************************/
		//ft_put_help.c
/*****************************************************************/
void	ft_put_help(char *name, t_option *op)
{
	ft_printf("%s helper\n"
	"\n\t -B : print the binary version of the source code.\n\t -D : print the"
	" decimal version of the source code.\n\t -e : make the compiler sensible"
	" for errors.\n\t -h : show this message.\n\t -H : "
	"print the hexa-decimal version of the source code.\n\t -o : print "
	"description of op-codes.\n\t -p : Print a detailed description of the source"
	" file.\n\t -s :"
	" print symboles table.\n\t -S : print label size of op-code.\n\t -u : print"
	" usage.\n\t -t : print information about type of each op-code.\n"
	"", name);
	ft_put_usage(name, op);
	exit(0);
}

/*****************************************************************/
		//exe.c
/*****************************************************************/

void	run_option(t_option *op, t_player *player, t_op *op_tab[NBR_OP])
{
	if (op->B)
		ft_put_bin_source(player);
	if (op->D)
		ft_put_decimal_source(player);
	if (op->H)
		ft_put_hexa_source(player);
	if (op->d || op->o || op->p || op->t || op->S)
	{
		if (op->d)
			ft_put_desc_param(op_tab);
		if (op->o)
			ft_put_op(op_tab);
		if (op->p)
			ft_put_player(player);
		if (op->t)
			ft_put_type_param(op_tab);
		if (op->S)
			ft_put_size_label(op_tab);
		exit(0);
	}
}

void	run(t_charlist *file, char *url_output, t_option *op, char *name)
{
	t_player player;
	t_charlist *file_clean;
	t_op *op_tab[NBR_OP];

	if (op->h)
		ft_put_help(name, op);
	if (op->u)
		ft_put_usage(name, op);
	ft_bzero(&player, sizeof(player));
	player.url_output = url_output;
	file_clean = ft_clean_file(file);
	ft_get_op_tab(op_tab);
	if (!ft_extract_info(file_clean, &player, op_tab))
		ft_error_reading_file(ERROR_EMPTY_FILE);
	if (ft_get_size_program(player.src) > CHAMP_MAX_SIZE)
		ft_warning(WARNING_SIZE_CHAMP,
	ft_get_size_program(player.src), NULL, op);
	ft_translate(&player, op_tab, op);
	run_option(op, &player, op_tab);
	ft_make_out_put(&player);
	ft_dell_list_charlist(&file_clean);
	ft_free_optab(op_tab);
	ft_free_player(&player);
}

int	main(int argc, char **argv)
{
	t_charlist		*file;
	char                    *param;
	char			*url_output;
	int			pt;
	t_option		op;

	file = NULL;
	ft_init_option(&op);
	param = ft_mat_to_str(argv, 1);
	if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else
	{
		pt = ft_extract_options(param, &op, argv[0]);
		url_output = ft_manage_url(param + pt);
		if (!ft_read_url_file(param + pt, &file))
			ft_error_reading_file(ERROR_READING_FILE);
		ft_strdel(&param);
		run(file, url_output, &op, argv[0]);
		ft_dell_list_charlist(&file);
//		ft_put_option(&op);
	}
	return (0);
}
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

// close the file after reading in the asm and the vm

/*****************************************************************/
	//VM
/*****************************************************************/
BOOL	ft_check_signature(unsigned char r[4])
{
	unsigned int *ret;
	int i;
	int size;

	size = sizeof(int);
	ret = ft_int_to_byts(COREWAR_EXEC_MAGIC, size);
	i = 0;
	while (i < size)
	{
		if (r[i] != ret[i])
		{
//			ft_printf("ici %d   %d\n", r[i], ret[i]);
			free(ret);
			return (F);
		}
		i++;
	}
	free(ret);
	return (T);	
}

/*****************************************************************/
		//ft_put_oct.c
/*****************************************************************/
void	ft_put_oct(unsigned char r[4])
{
	ft_printf("[%c, %c, %c, %c]", r[0], r[1], r[2], r[3]);
	ft_printf("[%.3d, %.3d, %.3d, %.3d]", r[0], r[1], r[2], r[3]);
}

/*****************************************************************/
		//ft_get_next_oct.c
/*****************************************************************/
BOOL	ft_get_next_oct(int fd, unsigned char (*tab)[4])
{
	unsigned char buf[1];
	int i;
	int size;

	i = 0;
	size = sizeof(int);
	while ( i < size)
	{
		if (!read(fd, &buf, 1))
			return (F);
		(*tab)[i] = buf[0];
//		ft_printf("i =[%d] = %d\t",i, buf[0]);
		i++;
	}
//	ft_printf("\n");
	return (T);
}

/*****************************************************************/
		//ft_byts_to_int.c
/*****************************************************************/
int	ft_byts_to_int(unsigned char b[4])
{
	return ((((((b[0] << 8) | b[1]) << 8) | b[2]) << 8) | b[3]);
}


/*****************************************************************/
		//ft_u_str_to_str.c
/*****************************************************************/
char	*ft_u_str_to_str(unsigned char str[4])
{
	char *ret;
	int i;

	i = 0;
	ret = ft_strnew(4);
	while (i < 4)
	{
		ret[i] = str[i];
//		ft_printf("i =[%d] = %d\t",i, ret[i]);
		i++;
	}
//	ft_printf("\n");
	return (ret);
}

/*****************************************************************/
		//ft_get_vm_magic.c
/*****************************************************************/
void	ft_get_vm_magic(int fd)
{
	unsigned char oct[4];

	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
		"<probleme signature> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
//	ft_put_oct(oct);
	if (!ft_check_signature(oct)) // detailes option bonus
	{
		ft_printf("{red}signature Ko\n{eoc}");
		exit(0);
	}
	else
		ft_printf("signature {green}ok\n{eoc}");
}

/*****************************************************************/
		//ft_get_vm_name.c
/*****************************************************************/
char	*ft_get_vm_name(int fd)
{
	unsigned char oct[4];
	char *name;
	char *temp;
	int byt;
	
	byt = 0;
	name = NULL;
	while(byt < (PROG_NAME_LENGTH / 4))
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
		{
			ft_printf("{red}Error reading file"
			"<name part> reaching unexpecting eof 2\n{eoc}");
			ft_printf("{red}Error while reading name Ko\n{eoc}");
			exit(0);
		}
	//	if (byt % 2)
	//		ft_printf("\n");
	//	ft_put_oct(oct);
		temp = ft_u_str_to_str(oct);
		name = ft_strjoin_clear(&name, &temp, BOTH);
		byt++;
	}
	return (name);
}

/*****************************************************************/
		//ft_get_vm_size.c
/*****************************************************************/
int	ft_get_vm_size(int fd)
{
	unsigned char oct[4];
	int size;
	
	size = 0;
	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
		"<size programme> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
//		ft_put_oct(r);
	size = ft_byts_to_int(oct);
	if(size > CHAMP_MAX_SIZE)
	{
		ft_printf("{red}Error size programme"
		"<size programme = %d> can not be superior to 1\n{eoc}",
		size, CHAMP_MAX_SIZE);
		exit(0);
	}
	return (size);
}

/*****************************************************************/
		//ft_is_null.c
/*****************************************************************/
BOOL	ft_is_null(int fd)
{
	unsigned char oct[4];
	int	val;

	if (!ft_get_next_oct(fd, &oct))
	{
		ft_printf("{red}Error reading file"
		"<null format> reaching unexpecting eof 1\n{eoc}");
		exit(0);
	}
//		ft_put_oct(r);
	val = ft_byts_to_int(oct);
	if(val)
	{
		ft_printf("{red}Error fomrat programme"
		"<null programme>\n{eoc}");
		exit(0);

	}
	return (T);
}

/*****************************************************************/
		//ft_get_vm_comment.c
/*****************************************************************/
char	*ft_get_vm_comment(int fd)
{
	unsigned char oct[4];
	char *comment;
	char *temp;
	int byt;
		
	byt = 0;
	comment = NULL;
	while(byt < (PROG_COMMENT_LENGTH / 4))
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
		{
			ft_printf("{red}Error reading file"
			"<comment part> reaching unexpecting eof 3\n{eoc}");
			ft_printf("{red}Error while reading name Ko\n{eoc}");
			exit(0);
		}
//		if (t % 2)
//			ft_printf("\n");
//		ft_put_oct(r);
		temp = ft_u_str_to_str(oct);
		comment = ft_strjoin_clear(&comment, &temp, BOTH);
		byt++;
	}
	return (comment);
}

/*****************************************************************/
		//ft_get_vm_src.c
/*****************************************************************/
/*char		*get_vm_src(int fd)
{
	unsigned char oct[4];
	char *src;
	char *temp;
	BOOL rd;

	rd = T;
	src = NULL;
	while(rd)
	{
		ft_bzero(&oct, sizeof(oct));
		if (!ft_get_next_oct(fd, &oct))
			rd = F;
		temp = ft_u_str_to_str(oct);
		src = ft_strjoin_clear(&src, &temp, BOTH);
	}
	return (src);
}
*/

/*****************************************************************/
		//ft_get_type_args_bin.c
/*****************************************************************/
/*int	is_direct(int ocp, int pos)
{
	if (pos == 1)
		return (T_DIR_P1);
	else if (pos == 2)
		return (T_DIR_P2);
	else
		return (T_DIR_P3);
}

int	is_indirect(int ocp, int pos)
{
	if (pos == 1)
		return (T_IND_P1);
	else if (pos == 2)
		return (T_IND_P2);
	else
		return (T_IND_P3);
}

int	is_register(int ocp, int pos)
{
	if (pos == 1)
		return (T_REG_P1);
	else if (pos == 2)
		return (T_REG_P2);
	else
		return (T_REG_P3);
}
*/
/*
	utiliser les printf pour afficher le type des variables 
	dans la vm !!!!
*/
/*
int	ft_get_type_args_bin(int ocp, int nbr_arg)
{
	if (is_direct(ocp, id_arg))//ft_printf("{red} DIRECT {eoc}");
		return (get_id_pos_direct(pos + 1));	
	if (is_indirect(ocp, id_arg))//ft_printf("{yellow} INDIRECT {eoc}");
		return (get_id_pos_indirect(pos + 1));	
	if (is_register(ocp, id_arg))//ft_printf("{BLUE} registre {eoc}");
		return (get_id_pos_register(pos + 1));	
	return (0);
}
i*/


t_instlist	*ft_get_vm_src(int fd, int size_prog)
{
	char *src;
	unsigned char buf[1];
	int i;

	i = 0;
	src = ft_strnew(size_prog);
	while(i < size_prog)
	{
		if(!read(fd, &buf, 1))
		{
			ft_printf("eoor\n");
			exit(0);
		}
		src[i] = buf[0];
		ft_printf("i =[%xd] = %x\t",i,
		src[i]);
		if(i % 4 == 0)
			ft_printf("\n");
		i++;
	}
/*
	src = get_vm_src(fd);
	ft_printf("\nsrc {green} ok %S\n<%d>{eoc}\n", src, ft_strlen(src));
*/
	i = 0;
	ft_printf("\n\n/ ************************** \\ \n\n", src[i]);
	while(i < size_prog) 
	{
		ft_printf("%.2x ", (unsigned char)src[i]);
		i++;
		if (i % 8 == 0)
			ft_printf("  ");
		if (i % 16 == 0)
			ft_printf("\n");
	}	
	ft_printf("\n\n/ ************************** \\ \n\n", src[i]);
	t_op *op_tab[NBR_OP];
	ft_get_op_tab(op_tab);
	ft_put_size_label(op_tab);
	int opr = 0;
	i = 0;
	while(i < size_prog) 
	{
		opr = src[i];
		ft_printf(" i = %d\n", i);
		if (src[i] < 17 && src[i] > 0)// error
			ft_printf("{green} op = %.2x {eoc}", src[i]);
		else
		{
			ft_printf("{red} exit %d   [%d]{eoc}", i, src[i]);
		
			break;
		}
		ft_printf(" name {%s} nbr param %d "
		, op_tab[opr]->name, op_tab[opr]->nbr_param);
		//opr = src[i];
		i++;
		if (opr == 1 || opr == 12 || opr == 9)
		{
			if (opr == 12 || opr == 9)
				i+= 2;
			else
				i += 4;	
		}
		else if(ft_is_need_desc_op( op_tab[opr]->name, op_tab))
		{
			ft_printf(" {yellow}desc{eoc} [%.2x] ",(unsigned char) src[i]);
			ft_printf(" {yellow}desc{eoc} [%.8b] \n",(unsigned char) src[i]);

			unsigned char desc = src[i];
			i++;
			ft_printf(" desc arg  = %.8b \n", (unsigned char)desc);

			//desc = desc >> 2;
			
			unsigned char arg_3;// = desc & 0x3;
		//	desc = desc >> 2;
			arg_3 = desc >> 6;
			ft_printf(" desc arg 1 = %.32b ", (unsigned char)arg_3);
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}	
			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				int pas = op_tab[opr]->size_label;
				i+= pas ;
				
			}else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i += 2;
			}else
				ft_printf("no arg 1");

			ft_printf("\n");
		//	desc = desc >> 2;
			unsigned char arg_q = (desc << 2);
			arg_3 = arg_q >> 6;
			ft_printf(" desc arg 2 = %.32b ", (unsigned char)arg_3);
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				i++;
			}
			else if(arg_3 == IND_CODE)
			{
				int pas = op_tab[opr]->size_label;
				ft_printf("indirect  pas = %d", pas);
				i +=2;//= pas;
			}else
				ft_printf("no arg 2");

			ft_printf("\n");

			arg_q = (desc << 4);
			arg_3 = arg_q >> 6;
			ft_printf(" desc arg 3 = %.32b ", (unsigned char)arg_3);
			if(arg_3 == REG_CODE)
			{
				ft_printf("registre ");
				i++;
			}
			else if(arg_3 == DIR_CODE)
			{
				ft_printf("direct ");
				i+= 2;
			}else if(arg_3 == IND_CODE)
			{
				ft_printf("indirect ");
				i+= 2;
			}
			else
				ft_printf("no arg 3");

/*
			int arg_1 = DESC_REG & ;
			int arg_2 = DESC_DIR & ;
			int arg_3 = DESC_IND & ;
*/

// faire des decalage binaire >> 2 et extraire  les deux bit tout a fait a roite puis les 
// comparer avec >REG_CODE/DIR_CODE/IND_CODE< pour conaitre le type des l'args
// en conaissant le type des args ont peut deduire
//	si le type est bien coherent
//		<si la desc dit qu'il ya un reg et le num est superieur a ce qui est reconnu>
//	la taille de representation de chaque arg

/*	

		//	if (src[i] & T_REG_P1)
				ft_printf("1 REG - size = {%d}, [%.8b]\n", op_tab[opr],
				T_REG_P1);
		//	if (src[i] & T_REG_P2)
				ft_printf("2 REG - size = {%d}, [%.8b]\n", op_tab[opr],
				T_REG_P2);
		//	if (src[i] & T_REG_P3)
				ft_printf("3 REG - size = {%d}, [%.8b]\n", op_tab[opr],
				T_REG_P3);
*/
		}
		else
		 i++;
		//is need OCP <+1> else faire directement les tailles des arguments

		//size parame      ->error
		ft_printf("\n");
//		ft_printf("%.2x ", (unsigned char)src[i]);
/*				i = i + op_tab[opr]->nbr_param;
		if (i == j)
			i = size_prog;
		else
			j = i;
*///		if (i % 8 == 0)
//			ft_printf("  ");
//		if (i % 16 == 0)
//			ft_printf("\n");

		char *l= NULL;
		get_next_line(0, &l);
		ft_strdel(&l);
//		ft_temporize(5);
	}

	ft_printf(" end index = %d\n", i);
//	ft_oct_to_instlist(src);
	ft_free_optab(op_tab);
	ft_strdel(&src);
	return (NULL);
}

/*****************************************************************/
		//main_vm.c
/*****************************************************************/
/*int	main(int argc, char **argv)
{
	int fd;
	
	fd = ft_open_r_file(argv[1]);
	ft_get_vm_magic(fd);
	char *name = ft_get_vm_name(fd);
	ft_printf("\nname {green}ok %s\n{eoc}", name);
	ft_strdel(&name);
	if (ft_is_null(fd))
		ft_printf("{green}ok null{eoc}\n");
	else
	{
		ft_printf("{redko{eoc}\n");
		exit(0);
	}
	int size = 0;
	ft_printf("\nsize {green} %d {eoc}\n", size = ft_get_vm_size(fd));

	char *comment;
	ft_printf("\ncomment {green}ok %s\n{eoc}", comment = ft_get_vm_comment(fd));
	ft_strdel(&comment);
	if (ft_is_null(fd))
		ft_printf("{green}ok null{eoc}\n");
	else
	{
		ft_printf("{red}ko{eoc}\n");
		exit(0);
	}
	ft_get_vm_src(fd, size);

	(void)argc;
	(void)argv;
	return (0);
}*/
