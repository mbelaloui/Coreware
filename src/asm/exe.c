#include "../../inc/asm.h"

/*****************************************************************/
		//ft_put_inst.c
/*****************************************************************/
void	ft_put_inst(t_inst *inst)
{
	ft_printf("address inst{green}%d{eoc}\n\n", inst->position);
	ft_printf("label : [%s]\nop  {%s}  args [",
	inst->label, inst->opcode);
	ft_put_list_charlist_join(inst->param);
	ft_printf("]\n");
	ft_printf("size op \t[%d]\n",inst->size[OPPR]);
	if (inst->size[ARG1] != -1)
		ft_printf("size arg 1 \t[%d]\n",inst->size[ARG1]);
	if (inst->size[ARG2] != -1)
		ft_printf("size arg 2 \t[%d]\n",inst->size[ARG2]);
	if (inst->size[ARG3] != -1)
		ft_printf("size arg 3 \t[%d]\n",inst->size[ARG3]);
	if (inst->size[DESC] != -1)
		ft_printf("+ [%d] size description\n",inst->size[DESC]);
	ft_printf("size inst {green}%d{eoc}\n\n", inst->size_inst);
}

/*****************************************************************/
		//ft_put_instlist.c
/*****************************************************************/
void	ft_put_instlist(t_instlist *list)
{
	int size_program;

	size_program = 0;
	while (list)
	{
   	ft_printf(" +++++++++++++++++++++++++++++++++++++++++++++++++\n");
		ft_put_inst(list->data);
		size_program += list->data->size_inst;
		list = list->next;
	}

	ft_printf("size programme %d \n", size_program);
}

/*****************************************************************/
		//ft_put_player.c
/*****************************************************************/

void	ft_put_player(t_player *player)
{
	ft_printf("name\t\t\t[%s]\ndesc\t\t\t[%s]\n\nurl out_put file\t[%s]\n"
	,player->name, player->description, player->url_output);
	ft_printf("\n\n\n");
	ft_printf("size inst :\n\n");
	ft_put_instlist(player->src);
}


/*****************************************************************/
		//ft_free_inst.c
/*****************************************************************/
void	ft_dell_inst(t_inst **inst)
{
	ft_strdel(&((*inst)->label));
	ft_strdel(&((*inst)->opcode));
	ft_strdel(&((*inst)->add));
	ft_dell_list_charlist(&(*inst)->param);
	free(*inst);
	*inst = NULL;
}

/*****************************************************************/
		//ft_dell_bgn_intlist.c
/*****************************************************************/
BOOL	ft_dell_list_instlist(t_instlist **to_free)
{
	t_instlist	*pt;

	if (!to_free || !(*to_free))
		return (F);
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		*to_free = (*to_free)->next;
		ft_dell_inst(&(pt->data));
		free(pt);
	}
	*to_free = NULL;
	return (T);
}

/*****************************************************************/
		//ft_free_player.c
/*****************************************************************/
	
void	ft_free_player(t_player *player)
{
	ft_strdel(&player->name);
	ft_strdel(&player->description);
	ft_strdel(&player->url_output);
	ft_dell_list_instlist(&player->src);
	//	ft_free_inst(&inst); //delet this ligne
}

/*****************************************************************/
		//ft_free_optab.c
/*****************************************************************/
void	ft_free_optab(t_op *op_tab[NBR_OP])
{
	int i;

	i = 0;
	while (i < NBR_OP)
	{
		ft_strdel(&op_tab[i]->name);
		free(op_tab[i]);
		i++;
	}
}
/*****************************************************************/
		//ft_add_end_instlist.c
/*****************************************************************/
BOOL    ft_add_end_instlist(t_inst *inst, t_instlist **list)
{
	t_instlist      *pt_list;
	t_instlist      *temp;

	if (!inst)
		return (F);
	temp = malloc(sizeof(*temp));
	temp->data = inst;
	temp->next = NULL;
	if (!(*list))
		*list = temp;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp;
	}
	return (T);
}

/*****************************************************************/
		//ft_error_label.c
/*****************************************************************/
void	ft_error_label(int error, char *label, char c, char *str)
{
//`"`	ft_printf("error == %d\n", error);
	if (error == ERROR_END_CHAR_LABEL)
		ft_printf("error char end of label expected <%s%c>\n"
				"found <%s>\n", label,LABEL_CHAR, str);
	else if (error == ERROR_FORMAT_LABEL)
		ft_printf("error format label expected <%s%c>\n"
				"found <%s%c>\nno end char label <%c> found\n"
			, label,LABEL_CHAR,label,c, LABEL_CHAR);
	else if (error == ERROR_FORMAT_LABEL_ARG)
		ft_printf("error format label arg\n");
	else if (error == ERROR_LABEL_NOT_DECLARED)
		ft_printf("{red}error label %s used but not declared{eoc}\n", label);
	exit(error);
}

/*****************************************************************/
		//ft_error_op.c
/*****************************************************************/
void	ft_error_op(int error, char *str)
{
//`"`	ft_printf("error == %d\n", error);
	if (error == ERROR_OP)
		ft_printf("error instruction <%s> not found\n", str);
/*	else if (error == ERROR_FORMAT_OPLABEL)
		ft_printf("error format label expected <%s%c>\n"
				"found <%s%c>\nno end char label <%c> found\n"
			, label,LABEL_CHAR,label,c, LABEL_CHAR);
*/	exit(error);
}

/*****************************************************************/
		//ft_error_head.c
/*****************************************************************/
void	ft_error_head(int error, char *str_file)
{
	char **sc;

	sc = ft_strsplit(str_file, SEP);
	if (error == ERROR_FORMAT_NAME || error == ERROR_FORMAT_COMMENT)
	{
		ft_printf("{yellow}Error format description file.{eoc}\n"
		"expected <{red}%s {eoc}\"%s\">\nfound    <{red}%s{eoc}>\n"
		"NB : the description can not be empty.\n",
		(error == ERROR_FORMAT_NAME) ? NAME_CMD_STR : COMMENT_CMD_STR,
		(error == ERROR_FORMAT_NAME) ? NAME_CMD_PR : COMMENT_CMD_PR,
		sc[0]);
	}
	else
	{
		ft_printf("{yellow}Error unknown param description file.{eoc}\n"
		"expected <{red}%s {eoc}\"%s\">\nfound    <{red}%s{eoc}>",
		(error == ERROR_HEAD_NAME) ? NAME_CMD_STR : COMMENT_CMD_STR,
		(error == ERROR_HEAD_NAME) ? NAME_CMD_PR : COMMENT_CMD_PR,
		sc[0]);
	}
	exit(error);
}

/*****************************************************************/
		//ft_error_inst.c
/*****************************************************************/
void	ft_error_inst(int error)
{
	if (error == ERROR_INSTRUCTION)
		ft_printf("error instruction \n");
	exit(0);
}
			
/*****************************************************************/
		//ft_error_args.c
/*****************************************************************/
void	ft_error_args(int error, char *op, char *args, char *arg)
{
	if (error == ERROR_ARG_NULL)
		ft_printf("error no args found : [%s %s]\n", op, args);
	else if (error == ERROR_NBR_ARG)
		ft_printf("error nbr args in instruction [%s %s]\n", op, args);
	else if (error == ERROR_FORMAT_ARG)
		ft_printf("error format args in instruction [%s %s]\n", op, args);
	else if (error == ERROR_TYPE_ARG)
		ft_printf("error type args [%s] in instruction [%s %s]\n",arg, op, args);
	else
		ft_printf("error args [%s %s]\n", op, args);
	exit(error);
}

/*****************************************************************/
		//ft_new_inst.c
/*****************************************************************/
t_inst	*ft_new_inst(char *label, char *op, t_charlist *args)
{
	t_inst *ret;
	int	i;

	if (!(ret = malloc(sizeof(*ret))))
		exit(0);
	ret->label = label;
	ret->opcode =op;
	ret->param = args;
	i = 0;
	while (i < 6)
	{
		ret->size[i] = -1;
		i++;	
	}
	ret->add = NULL;
	ret->position = 0;
	/*i = 0;
	while (i < 6)
	{
			ret->add[i] = -1;
		i++;	
	}
*/
	return(ret);
}

/*****************************************************************/
		//ft_extract_simple_comment.c
/*****************************************************************/
BOOL		is_start_simpl_comment(char *str)
{
	if ((str[0] == COMMENT_CHAR_1 || str[0] == COMMENT_CHAR_2)
		|| (str[0] == COMMENT_CHAR_3 && str[1] == COMMENT_CHAR_3))
		return (T);
	return (F);
}

char		*ft_extract_simpl_comment(char *file)
{
	int  i;
	int  y;
	char *ret;

	i = 0;
	y = 0;
	ret = ft_strnew(ft_strlen(file));
	while (file[i])
	{
		if (file[i] == DEF)
		{	
			ret[y++] = file[i++];
			while (file[i] && file[i] != DEF)
				ret[y++] = file[i++];
		}
		else if (is_start_simpl_comment(file + i))
		{
			while (file[i] && file[i] != SEP)
				i++;
		}
		if (!file[i]) 
			break;
		ret[y++] = file[i++];		
	}
	return (ret);
}

/*****************************************************************/
		//ft_extract_ml_comment.c
/*****************************************************************/
BOOL		is_start_ml_comment(char *str)
{
	if (str[0] == COMMENT_CHAR_3 && str[1] == COMMENT_CHAR_4)
		return (T);
	return (F);
}

BOOL		is_end_ml_comment(char *str)
{
	if (str[0] == COMMENT_CHAR_4 && str[1] == COMMENT_CHAR_3)
		return (T);
	return (F);
}

static int	get_index_end_ml_comment(char *file)
{
	int i;

	i = 2;
	while (file[i] && !is_end_ml_comment(file + i))
		i++;
	if (file[i] && is_end_ml_comment(file + i))
		i += 2;
	return (i);	
}


char		*ft_extract_ml_comment(char *file)
{
	int  i;
	int  y;
	char *ret;

	i = 0;
	y = 0;
	ret = ft_strnew(ft_strlen(file));
	while (file[i])
	{
		if (file[i] == DEF)
		{	
			ret[y++] = file[i++];
			while (file[i] && file[i] != DEF)
				ret[y++] = file[i++];
		}
		else if (is_start_ml_comment(file + i))
			i += get_index_end_ml_comment(file + i);
		if (!file[i]) 
			break;
		ret[y++] = file[i++];
	}
	return (ret);
}

/*****************************************************************/
		// ft_clean_file.c
/*****************************************************************/
void	check_for_bad_caracter(t_charlist *file)
{
	char *temp;

	if (!(temp = ft_charlist_to_str(file, SPS)))
		ft_error_reading_file(ERROR_EMPTY_FILE);
	if(ft_is_c_in_str(SEP, temp))
		ft_error_reading_file(ERROR_BAD_CHAR_FILE);
	ft_strdel(&temp);
}

t_charlist	*ft_clean_file(t_charlist *file)
{
	char *str_file;
	char *temp;
	t_charlist *ret;

	// convert charlist to str join whit SEP
	// return null if file s empty


	check_for_bad_caracter(file);
	if (!(str_file = ft_charlist_to_str(file, SEP)))
		return (NULL);
	// phase 1 manage simple comment starting char "; // #"
	temp = str_file;
	str_file = ft_extract_simpl_comment(str_file);
	ft_strdel(&temp);

	// phase 2 manage multi ligns comment starting char " /* "
	temp = str_file;
	str_file = ft_extract_ml_comment(str_file);
	ft_strdel(&temp);

	// convert str to charlist split compared to SEP
	ret = ft_str_to_charlist(str_file, SEP);
	ft_strdel(&str_file);
	return (ret);
}

/*****************************************************************/
		//ft_skiep_spaces.c
/*****************************************************************/
int	ft_skip_spaces(char *str_file)
{
	int i;

	i = 0;
	while(ft_isblank(str_file[i]) || str_file[i] == SEP)
		i++;
	return (i);
}

/*****************************************************************/
		//ft_get_index_end.c
/*****************************************************************/
int	ft_get_index_end(char *str_file)
{
	int i;
	int num_sep;

	num_sep = 2;
	i = 0;
	while(str_file[i] && num_sep > 0)
	{
		if (str_file[i] == DEF)
			num_sep--;
		i++;
	}
	if (num_sep && !str_file[i])
		return (-1);
	return (i);
}

/*****************************************************************/
		//ft_get_data.c
/*****************************************************************/
int	ft_get_data(char *str, char **data)
{
	int end_def;

	if (str[0] != DEF || (end_def = ft_get_index_end(str)) == -1)
		return (-1);
	*data = ft_strcut(str, 1, end_def - 1);
	return (end_def);
}

/*****************************************************************/
		//ft_replace_char_in_str.c
/*****************************************************************/
char	*ft_replace_char_in_str(char *str, char rep, char repwith)
{
	char *ret;
	int  len;
	int i;

	ret = NULL;
	if (str && rep && repwith)
	{
		i = 0;
		len = ft_strlen(str);
		ret = ft_strnew(len);
		while (str[i])
		{
			ret[i] = (str[i] == rep) ? repwith : str[i];
			i++;
		}
	}
	return (ret);
}
/*****************************************************************/
		//ft_extraire_head_info.c
/*****************************************************************/
int	extraire_name(char *str_file, t_player *player)
{
	int start_cmd;
	int len;
	int ret;

	start_cmd = ft_skip_spaces(str_file);
	len  = start_cmd + ft_strlen(NAME_CMD_STR);
	if (!ft_strncmp(str_file + start_cmd, NAME_CMD_STR, ft_strlen(NAME_CMD_STR))
		&& str_file[len] == SPS)
        {
		len  = len + ft_skip_spaces(str_file + len);
		if ((ret = ft_get_data(str_file + len, &(player->name))) < 0)
			ft_error_head(ERROR_FORMAT_NAME, str_file);
		if (ft_isempty(player->name))
			ft_error_head(ERROR_FORMAT_NAME, str_file);
		ret += len;
	}
	else
		ft_error_head(ERROR_HEAD_NAME, str_file);
	return (ret);
}

int	extraire_description(char *str_file, t_player *player)
{
	int start_cmd;
	int len;
	int ret;

	start_cmd = ft_skip_spaces(str_file);
	len  = start_cmd + ft_strlen(COMMENT_CMD_STR);
	if (!ft_strncmp(str_file + start_cmd, COMMENT_CMD_STR, ft_strlen(COMMENT_CMD_STR))
		&& str_file[len] == SPS)
        {
		len  = len + ft_skip_spaces(str_file + len);
		if ( (ret = ft_get_data(str_file + len, &(player->description))) < 0)
			ft_error_head(ERROR_FORMAT_COMMENT, str_file);
		if (ft_isempty(player->description))
			ft_error_head(ERROR_FORMAT_COMMENT, str_file);
		ret += len;
	}
	else
		ft_error_head(ERROR_HEAD_COMMENT, str_file);
	return (ret);
}


void	restore_head(t_player *player)
{
	char *name;
	char *description;

	name = ft_replace_char_in_str(player->name, SEP,RET);
	ft_strdel(&player->name);
	player->name = name;
	description = ft_replace_char_in_str(player->description, SEP,RET);
	ft_strdel(&player->description);
	player->description = description;
}

int	ft_extraire_head_info(char *str_file, t_player *player)
{
	int pt_ret;

	pt_ret = extraire_name(str_file, player);/// si name est vide erreur
	pt_ret += extraire_description(str_file + pt_ret, player);/// si name est vide erreur
	restore_head(player);
	return (pt_ret);
}

/*****************************************************************/
		//ft_is_label.c
/*****************************************************************/
BOOL	ft_is_label(char *str)
{
	int i;

	if (ft_is_name_op(str) == -1)
	{
		i = 0;
		while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
			i++;
		return  (str[i]) ? F : T;
	}
	return (F);
}

/*****************************************************************/
		//ft_is_direct.c
/*****************************************************************/
BOOL	ft_is_direct(char *arg)
{
	if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			return (ft_is_label(arg + 2) ? T : F);
		else
			return (ft_isnumerique(arg + 1) ? T : F);
	}
	return (F);
}

/*****************************************************************/
		//ft_is_indirect.c
/*****************************************************************/
BOOL	ft_is_indirect(char *arg)
{
	if (arg[0] == LABEL_CHAR)
		return (ft_is_label(arg + 1) ? T : F);
	else if (ft_isnumerique(arg))
		return (T);
	return (F);
}

/*****************************************************************/
		//ft_is_register.c
/*****************************************************************/
BOOL	ft_is_register(char *arg)
{
	int id_reg;

	if (arg[0] == REGISTRE_CHAR)
	{
		if (ft_isdigit(arg[1]) && ft_isnumerique(arg + 1))
		{
			id_reg = ft_atoi(arg+1);
			if (!id_reg || id_reg > REG_NUMBER) 
				return (F);
			else //	ft_printf("registre id %d\n", id_reg);
				return (T);
		}
		else//	ft_printf("wrong format registre\n");
			return (F);
	}
	return (F);
}

/*****************************************************************/
		//ft_get_type_args.c
/*****************************************************************/
int	get_id_pos_direct(int pos)
{
	if (pos == 1)
		return (T_DIR_P1);
	else if (pos == 2)
		return (T_DIR_P2);
	else
		return (T_DIR_P3);
}

int	get_id_pos_indirect(int pos)
{
	if (pos == 1)
		return (T_IND_P1);
	else if (pos == 2)
		return (T_IND_P2);
	else
		return (T_IND_P3);
}

int	get_id_pos_register(int pos)
{
	if (pos == 1)
		return (T_REG_P1);
	else if (pos == 2)
		return (T_REG_P2);
	else
		return (T_REG_P3);
}

int	ft_get_type_args(char *arg, int pos)
{
	if (ft_is_direct(arg))//ft_printf("{red} DIRECT {eoc}");
		return (get_id_pos_direct(pos + 1));	
	if (ft_is_indirect(arg))//ft_printf("{yellow} INDIRECT {eoc}");
		return (get_id_pos_indirect(pos + 1));	
	if (ft_is_register(arg))//ft_printf("{BLUE} registre {eoc}");
		return (get_id_pos_register(pos + 1));	
	return (0);
}

/*****************************************************************/
	//ft_prepare_args.c
/*****************************************************************/
char	**ft_prepare_args(char **str, char *name_op, t_op *op, char **args)
{
	int i;
	char **tab_args;

	i = 0;
	if (!str[i])
		ft_error_args(ERROR_ARG_NULL, name_op, *args, NULL);
	while (str[i])
		*args = ft_strjoin_clear(args, &str[i++], FIRST);
	if ((*args)[0] == SEPARATOR_CHAR 
		|| (*args)[ft_strlen(*args) - 1] == SEPARATOR_CHAR)
		ft_error_args(ERROR_FORMAT_ARG, name_op, *args, NULL);

	tab_args = ft_strsplit(*args, SEPARATOR_CHAR);

//ft_putmat(tab_args);

	if ((int)ft_matlen(tab_args) != op->nbr_param)
		ft_error_args(ERROR_NBR_ARG, name_op, *args, NULL);
	return (tab_args);
}


/*****************************************************************/
	//ft_is_need_desc_op.c
/*****************************************************************/
BOOL	ft_is_need_desc_op(char *name_op, t_op *op_tab[NBR_OP])
{
	t_op *op;

	op = ft_get_op(op_tab, name_op);
	return (op->desc_param);
}

/*****************************************************************/
		//ft_get_size_inst.c
/*****************************************************************/
int	get_size_arg(char *arg, t_op *op_tab[NBR_OP], char *name)
{
	t_op *op;

	op = ft_get_op(op_tab, name);
	if (ft_is_direct(arg))
		return (op->size_label);
	if (ft_is_indirect(arg))
		return (IND_SIZE);
	if (ft_is_register(arg))
		return (REG_SIZE);
	return (-1);
}

int	get_size_inst(t_inst *inst)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (i < SIZE_INST)
	{
		if (inst->size[i] != -1)
			size += inst->size[i];
		i++;	
	}
	return (size);
}

void	ft_get_size_inst(t_inst *inst, t_op *op_tab[NBR_OP])
{
	int i;
	t_charlist *pt;

	inst->size[LABL] = (inst->label) ? 0 : -1;
	if (inst->opcode)
	{
		inst->size[OPPR] = 1;	
		inst->size[DESC] = (ft_is_need_desc_op(inst->opcode, op_tab))
		? 1 : -1;
		i = 3;
		pt = inst->param;
//		ft_printf("\n************************\n inst %s \n", inst->opcode);
		while (pt)
		{
			inst->size[i++] = get_size_arg(pt->data, op_tab,
			inst->opcode);	
//			ft_printf("\nvoila param size %d \n", inst->size[i - 1]);
			pt = pt->next;
		}
	}
	else
		inst->size[OPPR] = -1;
	inst->size_inst = get_size_inst(inst);
}


/*****************************************************************/
		//ft_handle_args.c
/*****************************************************************/
void	ft_handle_args(char **tab_args, char *name_op, char *args, t_op *op)
{
	int pos;
	int param;

	pos = 0;
	while (tab_args[pos])
	{
		if (!(param = ft_get_type_args(tab_args[pos], pos)))
			ft_error_args(ERROR_TYPE_ARG,
			name_op, args, tab_args[pos]);
		if (!(param & op->param))
			ft_error_args(ERROR_TYPE_ARG,
			name_op, args, tab_args[pos]);
		pos++;
	}
}

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
	ft_handle_args(tab_args, name_op, args, op);
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

void	ft_extraire_source(t_charlist *sc, t_player *player, t_op *op_tab[NBR_OP])
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
	/*            extraire le source code */
	str = ft_format_str(str_file+pt);
	ft_strdel(&str_file);
	t_charlist *sc = ft_str_to_format_charlist(str, SEP);
	
	// start extract source code
	ft_extraire_source(sc, player, op_tab);
	ft_dell_list_charlist(&sc);
	ft_strdel(&str);
//
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
//	ft_printf("<%s>\n<%s>\n\n", symbole, list->data);
		if (!ft_strcmp(list->data, symbole))
			return (list->add);
		list = list->next;
	}
	return (-1);
}

/*****************************************************************/
		//ft_add_symbole.c
/*****************************************************************/
BOOL    ft_add_symbole(char *data, int add, t_symbole **list)
{
	t_symbole      *temp_node;
	t_symbole      *pt_list;

	if (!(temp_node = ft_new_symbole(data, add)))
		return (F);
	if ( ft_is_in_symbole(data, *list) > -1)
		ft_printf("{yellow}warning, double declaration of"
		" label %s{eoc}\n", data);
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

void	check_symbole_tab(t_symbole *symbole)
{
	while (symbole)
	{
		if (!symbole->used)
		{
			ft_printf("{yellow} warning label [%s]"
			" declared but not used{eoc}\n", symbole->data);
		}
		symbole = symbole->next;
	}
}

void	ft_check_for_label(t_symbole *symbole, t_instlist *src)
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
	check_symbole_tab(symbole);
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
	arg1 = pt->data;
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

	ret = NULL;
	if (size == 4)
	{
		ret = malloc(sizeof(int) * 4);
		ret[3] = (((unsigned int)val) << 24) >> 24;
		ret[2] = (((unsigned int)val) << 16) >> 24;
		ret[1] = (((unsigned int)val) << 8) >> 24;
		ret[0] = ((unsigned int)val) >> 24;
	}
	else if (size == 2)
	{
		ret = malloc(sizeof(int) * 2);
		ret[1] = ((unsigned int)val << 24) >> 24;
		ret[0] = (((unsigned int)val) << 16) >> 24;
	}
	return (ret);
}

/*****************************************************************/
		//ft_translate.c
/*****************************************************************/
t_symbole	*init_symbole_tab(t_player *player)
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
			ft_add_symbole(sc->data->label, add, &symbole);
		add += sc->data->size_inst;
		sc = sc->next;
	}
	return (symbole);
}

	
char	*get_arg_bin(t_inst *inst, t_symbole *symbole)
{
	t_charlist *pt;

	pt = inst->param;
	int i = ARG1;
	int add_label;
	intmax_t add_out;
	unsigned int *ret;

	while (pt)
	{
		ft_printf("arg [%s] size = %d\n", pt->data, inst->size[i]);

		char *arg = pt->data;

		if (ft_is_direct(arg))// && !ft_is_label(arg))
		{
			
			if ((add_label = ft_is_in_symbole(arg + 2, symbole)) >-1)
			{
				add_out = add_label - inst->position;
				/*if (add_out < 0)
				{
				//	add_out++;
//			ft_printf(" size %d ", inst->size[i]);
			ft_printf(" dir_ref %ld + add_out %d = %ld\n\n",
			DIR_REF, add_out, DIR_REF + add_out);

				if (inst->size[i] == IND_SIZE)
					add_out = IND_REF + add_out;
				else if (inst->size[i] == DIR_SIZE)
					add_out = DIR_REF + add_out;
				}*/


		ret = ft_int_to_byts(add_out, inst->size[i]);

if (inst->size[i] == 2)
		ft_printf("{blue}label dir{eoc} -%s- add [%hd][%hd] \n",
		arg+ 2, ret[0],ret[1]);
else
	ft_printf("{blue}label dir{eoc} -%s- add [%hd][%hd] [%hd][%hd] \n"
	,arg + 2, ret[0],ret[1],ret[2],ret[3]);

free(ret);
			}
			else
		ft_printf("\tdirect *%d*\n",ft_atoi(arg + 1));
		}
		else if (ft_is_indirect(arg))
		{
			if ((add_label = ft_is_in_symbole(arg + 1, symbole)) >-1)
			{

				add_out = add_label - inst->position;
/*				if (add_out < 0)
				{
					add_out++;
				if (inst->size[i] == IND_SIZE)
					add_out = IND_REF + add_out;
				else if (inst->size[i] == DIR_SIZE)
					add_out = DIR_REF + add_out;
				}

*/
		ret = ft_int_to_byts(add_out, inst->size[i]);
if (inst->size[i] == 2)
		ft_printf("{blue}label ind {eoc} -%s- add [%hd][%hd] \n",
		arg+ 2, ret[0],ret[1]);
else
	ft_printf("{blue}label ind {eoc} -%s- add [%hd][%hd] [%hd][%hd] \n"
	,arg + 2, ret[0],ret[1],ret[2],ret[3]);

free(ret);
	
//	ft_printf("\t{blue}label ind {eoc} -%s- add [%hd][]  diff[%ld]\n",arg+1,
//			add_label, add_out);
		
		}else
		ft_printf("\tindirect <%d>\n",ft_atoi(arg ));
		}
		else if (ft_is_register(arg))
			ft_printf("\tregister [%d]\n",ft_atoi(arg+1 ));
						//return (DESC_DIR);
		pt = pt->next;
		i++;
	}
	return (0);
}

void	set_data(t_inst *inst, t_op *op_tab[NBR_OP], t_symbole *symbole)
{
	t_op *op;
	int desc;

	desc = 0;
	op = ft_get_op(op_tab, inst->opcode);
	ft_printf("inst position  = <{red}%d{eoc}>\n", inst->position);
	ft_printf("inst operation = <{red}%s{eoc}>  code = [%.2x]\n",
	inst->opcode, op->mnemonique);
//ft_printf("need desc %s\n", (inst->size[DESC] != -1) ? "oui" : "non" );
	if (inst->size[DESC] != -1)
	{	desc = ft_get_desc_args(inst->param);
	ft_printf("desc args = {green}%.8b {Yellow}%x {red} %d{eoc}\n",
	desc, desc, desc);
	}else
		ft_printf("no desc args\n");

	get_arg_bin(inst, symbole);

	ft_printf("\n\n");
}

void	run_translate(t_instlist *src, t_op *op_tab[NBR_OP], t_symbole *symbole)
{
	int size_inst;
	t_instlist *pt;

	pt = src;
	int i =0;
	while (pt)
	{
		size_inst = ft_get_size_bin_inst(pt->data->size);
		pt->data->add = ft_strnew(size_inst);
		set_data(pt->data, op_tab, symbole);
		
	//	ft_printf("size inst %d = %ld\n", i, size_inst);

		i++;
		pt = pt->next;
	}
	(void)src;
}

void	ft_translate(t_player *player, t_op *op_tab[NBR_OP])
{
	t_symbole *symbole;

	symbole = init_symbole_tab(player);
	ft_put_list_symbole(symbole);
	ft_check_for_label(symbole, player->src);

	run_translate(player->src, op_tab, symbole);

//	ft_put_player(player);
//	ft_put_list_symbole(symbole);

	ft_dell_list_symbole(&symbole);
	(void)op_tab;
}

/*****************************************************************/
		//exe.c
/*****************************************************************/
void	run(t_charlist *file, char *url_output)
{
	t_player player;
	t_charlist *file_clean;
	t_op *op_tab[NBR_OP];

	ft_bzero(&player, sizeof(player));
	player.url_output = url_output;
	file_clean = ft_clean_file(file);
	ft_get_op_tab(op_tab);
	if (!ft_extract_info(file_clean, &player, op_tab))
		ft_error_reading_file(ERROR_EMPTY_FILE);
	
	/************************************/
	//traslate code source
	ft_translate(&player, op_tab);

	ft_dell_list_charlist(&file_clean);
	ft_free_optab(op_tab);
	ft_free_player(&player);
}

int	main(int argc, char **argv)
{
	t_charlist		*file;
	char                    *param;
	char			*url_output;

	file = NULL;
	param = ft_mat_to_str(argv, 1);
	if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else if (argc > 2)
		ft_error_param(ERROR_MULTIPUL_PARAM, param);
	else
	{
		url_output = ft_manage_url(param);
		if (!ft_read_url_file(param, &file))
			ft_error_reading_file(ERROR_READING_FILE);
		ft_strdel(&param);
		run(file, url_output);
		ft_dell_list_charlist(&file);
	}
	(void)argc;
	(void)argv;
	
/*	
	unsigned int *ret;

	ft_printf("\n -------------------------\n");
	ret = ft_int_to_byts(4, 2);
ft_printf("val = [%hd][%hd] \n",ret[0],ret[1]);
	free(ret);
	ret = ft_int_to_byts(4, 4);
ft_printf("val = [%hd][%hd] [%hd][%hd] \n",ret[0],ret[1],ret[2],ret[3]);
	free(ret);
	ret = ft_int_to_byts(2, 2);
ft_printf("val = [%hd][%hd] \n",ret[0],ret[1]);
	free(ret);
	ret = ft_int_to_byts(2, 4);
ft_printf("val = [%hd][%hd] [%hd][%hd] \n",ret[0],ret[1],ret[2],ret[3]);
	free(ret);
	ret = ft_int_to_byts(-53, 2);
ft_printf("val = [%hd][%hd] \n",ret[0],ret[1]);
	free(ret);
	ret = ft_int_to_byts(-42, 2);
ft_printf("val = [%hd][%hd] \n",ret[0],ret[1]);
	free(ret);
	ret = ft_int_to_byts(-360, 2);
ft_printf("val = [%hd][%hd] \n",ret[0],ret[1]);
	free(ret);
	ret = ft_int_to_byts(633, 4);
ft_printf("val = [%hd][%hd] [%hd][%hd] \n",ret[0],ret[1],ret[2],ret[3]);
	free(ret);
*/
	return (0);
}
