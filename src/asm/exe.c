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
		ret[y++] = file[i++];
	}
	return (ret);
}

/*****************************************************************/
		// ft_clean_file.c
/*****************************************************************/

t_charlist	*ft_clean_file(t_charlist *file)
{
	char *str_file;
	char *temp;
	t_charlist *ret;

	// convert charlist to str join whit SEP
	// return null if file s empty
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

void	run(t_charlist *file)
{
	t_charlist *file_clean;

	ft_printf("the file is ready to be read\n");
	//ft_put_list_charlist(file);

	file_clean = ft_clean_file(file);

	// start extract information <head file>

	// start extract source code

	// traslate code source

	//ft_printf("\n\n\n");
	ft_put_list_charlist(file_clean);
	ft_dell_list_charlist(&file_clean);
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
