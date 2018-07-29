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
	{
		ft_printf("empty file\n");
		exit(0);
	}
	if(ft_is_c_in_str(SEP, temp))
	{
		ft_printf("bad caractere found\n");
		exit(0);
	}
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
int	skip_spaces(char *str_file)
{
	int i;

	i = 0;
	while(ft_isblank(str_file[i]) || str_file[i] == SEP)
		i++;
	return (i);
}

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

int	get_data(char *str, char **data)
{
	int end_def;

	if (str[0] != DEF || (end_def = ft_get_index_end(str)) == -1)
		return (-1);
	*data = ft_strcut(str, 1, end_def - 1);
	return (end_def);
}

int	extraire_name(char *str_file, t_player *player)
{
	int start_cmd;
	int len;
	int ret;

	start_cmd = skip_spaces(str_file);
	len  = start_cmd + ft_strlen(NAME_CMD_STRING);

	if (!ft_strncmp(str_file + start_cmd, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
		&& str_file[len] == SPS)
        {
		len  = len + skip_spaces(str_file + len);
		if ( (ret = get_data(str_file + len, &(player->name))) < 0)
		{
			ft_printf("{red}error bad format of definition of %s{eoc}", NAME_CMD_STRING);
			exit(-1);
		}
			if (ft_isempty(player->name))
			{
				ft_printf("empty description name \n");
				exit(0);
			}
			ret += len;
	}
	else // le fichier ne commance pas avec le nom du champion
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"// {red}<%s>{eoc}.\n"
		"expected  <{red}%s {eoc}\"NAME_CAHMPION\">\n"
		"found     <{red}%s{eoc}>", NAME_CMD_STRING, str_file);
		exit(0);
	}
	return (ret);
}

int	extraire_description(char *str_file, t_player *player)
{
	int start_cmd;
	int len;
	int ret;

	start_cmd = skip_spaces(str_file);
	len  = start_cmd+ ft_strlen(COMMENT_CMD_STRING);
	if (!ft_strncmp(str_file + start_cmd, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING))
		&& str_file[len] == SPS)
        {
		len  = len + skip_spaces(str_file + len);
		if ( (ret = get_data(str_file + len, &(player->description))) < 0)
		{
			ft_printf("{red}error bad format of definition of %s{eoc}\n", COMMENT_CMD_STRING);
			exit(-1);
		}
			if (ft_isempty(player->description))
			{
				ft_printf("empty description comment \n");
				exit(0);
			}
		ret += len;
	}
	else // le fichier ne commance pas avec le nom du champion
	{
		ft_printf("{yellow}Error unknown param description file{eoc}\n"// {red}<%s>{eoc}.\n"
		"expected  <{red}%s {eoc}\"NAME_PROGRAME\">\n"
		"found     <{red}%s{eoc}>", COMMENT_CMD_STRING, str_file);
		exit(0);
	}
	return (ret);
}

int	extraire_head_info(char *str_file, t_player *player)
{
	int pt_ret;

	pt_ret = extraire_name(str_file, player);/// si name est vide erreur
	pt_ret += extraire_description(str_file + pt_ret, player);/// si name est vide erreur
	return (pt_ret);
}

void	ft_free_player(t_player *player)
{
	ft_strdel(&player->name);
	ft_strdel(&player->description);
	//ft_strdel(&);
	//ft_strdel(&);
}

BOOL	extract_info(t_charlist *file, t_player *player)
{
	char *str_file;
	int pt;

	if (!(str_file = ft_charlist_to_str(file, SEP)))
		return (F);
	// start extract information <head file>
	pt = extraire_head_info(str_file, player);


	/*            extraire le source code */


	// start extract source code
	ft_printf("rest of the file<%s>\n", str_file+pt);

	ft_strdel(&str_file);
	return (T);
}

void	run(t_charlist *file)
{
	t_player player;

	ft_bzero(&player, sizeof(player));
	t_charlist *file_clean;

//	ft_printf("the file is ready to be read\n");
	file_clean = ft_clean_file(file);
//	ft_printf("the file is clean\n");

	if (!extract_info(file_clean, &player))
	{
		ft_printf("empty file\n");
		exit(0);
	}

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
