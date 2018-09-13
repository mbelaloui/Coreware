#include "../../inc/charlist.h"

/*
** input        list of sring
** output       formated sting
**
** cette fonction prend les elements de la list et les concataine dans une
** string en les separent avec le caractere definit
** les string sont formater de maniere a n'avoir qu'un seul " " entre chaque mot
*/

char	*ft_charlist_to_format_str(t_charlist *list, char c)
{
	char *ret;
	char *temp;

	ret = NULL;
	if (list)
	{
		ret = ft_format_str(list->data);
		list = list->next;
		while (list)
		{
			temp = ret;
			ret = ft_strjoin_sep(ret, list->data, c);
			ft_strdel(&temp);
			list = list->next;
		}
	}
	return (ret);
}
