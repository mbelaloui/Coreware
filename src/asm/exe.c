#include "../../inc/asm.h"

/*****************************************************************/
//		ft_extract_simple_comment.c
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
	len  = start_cmd+ ft_strlen(COMMENT_CMD_STR);
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

int	ft_extraire_head_info(char *str_file, t_player *player)
{
	int pt_ret;

	pt_ret = extraire_name(str_file, player);/// si name est vide erreur
	pt_ret += extraire_description(str_file + pt_ret, player);/// si name est vide erreur
	return (pt_ret);
}

/*****************************************************************/
		//ft_free_player.c
/*****************************************************************/
	
void	ft_free_player(t_player *player)
{
	ft_strdel(&player->name);
	ft_strdel(&player->description);
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
	exit(error);
}

/*****************************************************************/
		//ft_get_label.c
/*****************************************************************/
BOOL	ft_get_label(char *str, char **label)
{
	int i;
//	char *label;

	if (ft_is_name_op(str) == -1)
	{
		i = 0;
		while (str[i] && ft_is_c_in_str(str[i], LABEL_CHARS))
			i++;
		*label = ft_strcut(str, 0, i);
		if (str[i])
		{
			if (str[i] == LABEL_CHAR && !str[i + 1])
				return (T);// && ft_strdel(&label));
			else
				ft_error_label(ERROR_END_CHAR_LABEL, *label, str[i], str);
		}
		else
			ft_error_label(ERROR_FORMAT_LABEL, *label, str[i], 0);
//		ft_strdel(&label);
	}
//	else 	ft_printf("4-c'est pas un label <%s>\n", str);
	return (F);
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
		//ft_extract_source.c
/*****************************************************************/
BOOL	get_op(char *str, char **op)
{
	if (ft_isempty(str))
		return (F);
	if (ft_is_name_op(str) == -1)
		ft_error_op(ERROR_OP, str);
	*op = ft_strdup(str);
	return (T);
}

BOOL	get_args(char **str, char *op)
{
	int i;
	char *args;

	i = 0;
	args = NULL;
	while (str[i])
	{
		args = ft_strjoin_clear(&args, &str[i], FIRST);
		i++;
	}
	ft_printf("args = %s\n", args);

	ft_strdel(&args);
	(void)op;
	return (F);
}

void	ft_extraire_source(t_charlist *sc, t_player *player)
{
//	ft_put_list_charlist(sc);
	char **line;
	int nu;
	char *label;
	char *op;

	label =NULL;
	op =NULL;
	while (sc)
	{
		nu = 0;
		if (!ft_isempty(sc->data))
		{
			line = ft_strsplit(sc->data, SPS);
			if (ft_get_label(line[nu], &label))
			{
				nu++;
				ft_printf("c'est un label <%s>\n", label);
			}
			if (get_op(line[nu], &op))
			{
				nu++;
				ft_printf("op = %s\t", op);
				get_args(&(line[nu]), op);
			}
		//	else
		//		ft_printf("c'est pas un label [%s] <%s>\n", label, line[0]);
	//fonction pour decouper une ligne 
	//dedant detecter \il ya un label au debut 
	//si non voir quel opcode 
	//apres voir les conditions
			ft_free_mat(&line);
		ft_strdel(&label);
		ft_strdel(&op);
		}
		sc = sc->next;
	ft_printf(" ------------------------------------------------ \n");
	}

	(void)player;
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
	return (T);
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
		//exe.c
/*****************************************************************/
void	run(t_charlist *file)
{
	t_player player;
	t_op *op_tab[NBR_OP];
	t_charlist *file_clean;

	ft_bzero(&player, sizeof(player));
	file_clean = ft_clean_file(file);
	if (!ft_extract_info(file_clean, &player))
		ft_error_reading_file(ERROR_EMPTY_FILE);

//      ft_init_op_tab(op_tab);
//      ft_set_param(op_tab);

	/************************************/

	ft_get_op_tab(op_tab);

//	ft_put_desc_param(op_tab);
//	ft_put_op(op_tab);
//      ft_set_size_label(op_tab);
//	ft_put_size_label(op_tab);
	ft_free_optab(op_tab);

	/************************************/
	// traslate code source
	//ft_printf("\n\n\n");
	ft_dell_list_charlist(&file_clean);
	ft_free_player(&player);
}

int	main(int argc, char **argv)
{
	t_charlist		*file;
	char                    *param;
	
	file = NULL;
	param = ft_mat_to_str(argv, 1);
	if (argc == 1)
		ft_error_param(ERROR_NO_PARAM, param);
	else if (argc > 2)
		ft_error_param(ERROR_MULTIPUL_PARAM, param);
	else
	{
		ft_manage_url(param);
		if (!ft_read_url_file(param, &file))
			ft_error_reading_file(ERROR_READING_FILE);
		ft_strdel(&param);
		run(file);
		ft_dell_list_charlist(&file);
	}
	return (0);
}
