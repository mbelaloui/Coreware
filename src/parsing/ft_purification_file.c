#include "../../inc/asm.h"

/*
** a terminer ajouter les commentaires dans une liste
** split la fonction par apport a chaque type de comment
*/

void    manage_sep(char **ret)
{
	char *to_del;

	//      ft_printf("{red}\n 2 \n%s\n\n{eoc}", file +i);
	to_del = *ret;
	*ret = ft_strjoin(*ret, "\n");
	//      ft_printf("{yellow}\n %s\n{eoc}", ret);
	ft_strdel(&to_del);
}

int     manage_simple_comment(char *file, t_charlist **comment)
{
	int i;
	int start;

	i = 1;
	if (file[i] == COMMENT_CHAR_2)
		start = 2;
	else
		start = 1;
	//      ft_printf("{red}\n 3 \n%s\n\n{eoc}", file +i);
	while (file[i] && file[i] != SEP)
		i++;

//	ft_printf("7\n");

	ft_cut_add_charlist(file, start, i, comment);
	//      ft_cut_add_charlist(file, start, i, comment);    i - 1
	return (i);
}

int     manage_ml_comment(char *file, t_charlist **comment)
{
	int i;

	//      ft_printf("{red}\n 4 \n%s\n\n{eoc}", file +i);
	i = 2;
	while (file[i] && file[i] != '*' && file[i + 1] != '/')
		i++;
	ft_cut_add_charlist(file, 2, i, comment);
	// cut_add ....     i - 1
	if(file[i] && file[i] == '*' && file[i + 1] == '/')
		i += 2;
	return (i);
}

int     manage_simple_source(char *file, char **ret)
{
	int index;
	char *to_add;
	char *to_del;

	index = ft_get_index_end_line(file);
	to_add = ft_strcut(file,0,index);
	//      ft_printf("AP i = %d , index = %d \n",i, index);
	to_del = *ret;

	*ret = ft_strjoin(*ret, to_add);
	ft_strdel(&to_add);
	ft_strdel(&to_del);
	return (index);
}

char    *ft_purification_file(char *file, t_charlist **comment)
{
	int i;
	char *ret;

	i = 0;
	ret = ft_strnew(ft_strlen(file));
	while (file[i])
	{
		if (file[i] == SEP && i++)
			manage_sep(&ret);
		else if(file[i] == COMMENT_CHAR
				|| file[i] == COMMENT_CHAR_1
				|| (file[i] && file[i] == COMMENT_CHAR_2
					&& file[i+ 1] == COMMENT_CHAR_2))
			i += manage_simple_comment(file + i, comment);
		else if (file[i] && file[i] == '/' && file[ i + 1] == '*')
			i += manage_ml_comment(file + i, comment);
		else
			i += manage_simple_source(file + i, &ret);
	}
	return (ret);
}
