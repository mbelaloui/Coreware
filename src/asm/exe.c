#include "../../inc/asm.h"

/*****************************************************************/
		//ft_put_inst.c
/*****************************************************************/
void	ft_put_inst(t_inst *inst)
{
	ft_printf("label [%s] op  [%s]  args [",
	inst->label, inst->opcode);
	ft_put_list_charlist_join(inst->param);
	ft_printf("]\n");
}

/*****************************************************************/
		//ft_put_instlist.c
/*****************************************************************/
void	ft_put_instlist(t_instlist *list)
{
	while (list)
	{
		ft_put_inst(list->data);
		list = list->next;
	}
}

/*****************************************************************/
		//ft_put_player.c
/*****************************************************************/

void	ft_put_player(t_player *player)
{
	ft_printf("name\t\t\t[%s]\ndesc\t\t\t[%s]\n\nurl out_put file\t[%s]\n"
	,player->name, player->description, player->url_output);
	ft_printf("sources coude :\n");
	ft_put_instlist(player->src);
}


/*****************************************************************/
		//ft_free_inst.c
/*****************************************************************/
void	ft_dell_inst(t_inst **inst)
{
	ft_strdel(&((*inst)->label));
	ft_strdel(&((*inst)->opcode));
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
t_inst	*ft_new_inst(char *label, char *op, char **args)
{
	t_inst *ret;

	if (!(ret = malloc(sizeof(*ret))))
		exit(0);
	ret->label = label;
	ret->opcode =op;
	ret->param = ft_mat_to_charlist(args);


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
		//ft_is_label_arg.c
/*****************************************************************/
BOOL	ft_is_label_arg(char *str)
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
			return (ft_is_label_arg(arg + 2) ? T : F);
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
		return (ft_is_label_arg(arg + 1) ? T : F);
	else if (ft_isnumerique(arg))
		return (T);
	return (F);
}

/*****************************************************************/
		//ft_is_registre.c
/*****************************************************************/
BOOL	ft_is_registre(char *arg)
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

int	get_id_pos_registre(int pos)
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
	if (ft_is_registre(arg))//ft_printf("{BLUE} registre {eoc}");
		return (get_id_pos_registre(pos + 1));	
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
	if ((int)ft_matlen(tab_args) != op->nbr_param)
		ft_error_args(ERROR_NBR_ARG, name_op, *args, NULL);
	return (tab_args);
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
			ft_error_args(ERROR_TYPE_ARG, name_op, args, tab_args[pos]);
		if (!(param & op->param))
			ft_error_args(ERROR_TYPE_ARG, name_op, args, tab_args[pos]);
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
				ft_error_label(ERROR_END_CHAR_LABEL, *label, str[i], str);
		}
		else
			ft_error_label(ERROR_FORMAT_LABEL, *label, str[i], 0);
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

/*
	ft_printf("%s -> op = %#X\t nbr_param = %d  desc = %.9b\n",
	name_op,op->mnemonique, op->nbr_param, op->param);
*/

BOOL	get_args(char **str, char *name_op)
{
	char *args;
	char **tab_args;
	t_op *op_tab[NBR_OP];
	t_op *op;

	args = NULL;
	ft_get_op_tab(op_tab);
	op = ft_get_op(op_tab, name_op);
	tab_args = ft_prepare_args(str, name_op, op, &args);
	ft_handle_args(tab_args, name_op, args, op);
	ft_strdel(&args);
	ft_free_optab(op_tab);
	ft_free_mat(&tab_args);
	return (F);
}

t_inst	*quarry_line(t_charlist *sc,char *label, char *op)
{
	char **args;
	int nu;
	t_inst *inst;

	nu = 0;
	if (!ft_isempty(sc->data))
	{
		args = ft_strsplit(sc->data, SPS);
		if (get_label(args[nu], &label))
			nu++;
		if(get_op(args[nu], &op))
		{
			nu++;
			get_args(&(args[nu]), op);
		}
		inst = ft_new_inst(label, op, args + nu);
		ft_free_mat(&args);
		return (inst);
	}
	return (NULL);
}

void	ft_extraire_source(t_charlist *sc, t_player *player)
{
	char *label;
	char *op;
	t_instlist *src;
	t_inst *inst;

	src = NULL;
	op = NULL;
	label = NULL;
	while (sc)
	{
		if (!ft_isempty(sc->data))
		{
			inst = quarry_line(sc, label, op);
			if (inst == NULL)
				ft_error_inst(ERROR_INSTRUCTION);
			ft_add_end_instlist(inst, &src);
		}
		sc = sc->next;
	}
	player->src = src;
}

/*****************************************************************/
		//ft_extract_info.c
/*****************************************************************/
BOOL	ft_extract_info(t_charlist *file, t_player *player)
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
	ft_extraire_source(sc, player);
	ft_dell_list_charlist(&sc);
	ft_strdel(&str);
//
	return (T);
}

/*****************************************************************/
		//ft_translate_sc.c
/*****************************************************************/

void	ft_translate(t_player *player)
{
	ft_put_player(player);
}

/*****************************************************************/
		//exe.c
/*****************************************************************/
void	run(t_charlist *file, char *url_output)
{
	t_player player;
	t_charlist *file_clean;

	ft_bzero(&player, sizeof(player));
	player.url_output = url_output;
	file_clean = ft_clean_file(file);
	if (!ft_extract_info(file_clean, &player))
		ft_error_reading_file(ERROR_EMPTY_FILE);
	
	/************************************/
	//traslate code source
	ft_translate(&player);

	ft_dell_list_charlist(&file_clean);
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
	return (0);
}
