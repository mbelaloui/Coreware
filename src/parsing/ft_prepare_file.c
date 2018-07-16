#include "../../inc/asm.h"


/*
** cette fonction permet de prendre en compt les \n
** dans les declations dans le nom et description "  "
** elever les '\n' entre les ""
*/

void    manage_special_line(char **ret, int *cp, char **file, int *i)
{
	(*ret)[(*cp)++] = (*file)[(*i)++];
	while ((*file)[*i] && (*file)[*i] != DELIMITEUR)
	{
		if ((*file)[*i] != SEP)
			(*ret)[(*cp)++] = (*file)[(*i)++];
		else
		{
			(*ret)[*cp] = ' ';
			(*cp)++;
			(*i)++;
			while ((*file)[*i] == SEP)
				(*i)++;
		}
	}
	if ((*file)[(*i)] == DELIMITEUR)
		(*ret)[(*cp)++] = (*file)[(*i)++];
}

char    *ft_prepare_file(t_charlist *listfile, char c)
{
	char *ret;
	int cp;
	int i;
	char *file;

	ft_is_there_forbiden_char(listfile);
	cp = 0;
	i = 0;
	file = ft_charlist_to_str(listfile, c);
	ret = ft_strnew(ft_strlen(file));
	while (file[i])
	{
		if (file[i] == DELIMITEUR)
			manage_special_line(&ret, &cp, &file, &i);
		else
		{
			ret[cp] = file[i];
			cp++;
			i++;
		}
	}
	ft_strdel(&file);
	return (ret);
}
