
#include "../inc/op.h"

char    *ft_charlist_to_str(t_charlist *list, char c)
{
	char *ret;
	char *temp;
	
	ret = NULL;
	if(list)
	{
		ret = ft_strdup(list->data);
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

/*
** cette fonction permet de prendre en compt les \n
** dans les declations dans le nom et description "  "
*/

char	*ft_prepare_file(char *file)
{
	char *ret;
	int cp;
	int i;

	cp = 0;
	i = 0;
	ret = ft_strnew(ft_strlen(file));
	while (file[i])
	{
		if (file[i] == '"')
		{
			ret[cp] = file[i];
			cp ++;
			i ++;
			while (file[i] && file[i] != '"')
			{
				if (file[i] != SEP)
				{
					ret[cp] = file[i];
					cp ++;
				i++;
				}else
				{
					ret[cp] = ' ';
					cp++;
					i++;
					while (file[i] == SEP)
						i++;
				}
			}
			if (file[i] == '"')
			{
				ret[cp] = file[i];
				cp ++;
				i++;
			}
		}
		else
		{
			ret[cp] = file[i];
			cp++;
			i++;
		}
	}
	//ret[cp] = '\0';
	return (ret);
}



int	get_index_end_declaration(char *str)
{
	int i;

	i = 0;
//	ft_printf("%s\t 4444\n",str);
	while (str[i])
	{
		if (str[i] == DELIM_DECLARATION)
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_extract_comment(char *file)
{
	int i;
	int index;
	char *ret;
	char *to_add;
	char *to_del;
	
	ret = ft_strnew(ft_strlen(file));
	i = 0;
	while (file[i])
	{
		if (file[i] == DELIM_DECLARATION)
		{
			index = get_index_end_declaration(file + i + 1);
			to_add = ft_strcut(file,i,index + 1);
			to_del = ret;
			//ft_printf("aaaaaaaaaaaaaaaaa   %s\n", ret);
			ret = ft_strjoin(ret, to_add );
		//	ft_printf("aaaaaaaaaaaaaaaaa   %s\n", ret);
			ft_strdel(&to_del);
			ft_strdel(&to_add);
		}
		i++;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	t_charlist *file;
	char *url_file = argv[1];
	char *str;

	file = NULL;
	if (!ft_read_url_file(url_file, &file))
		return(0) ; /// cas d'erruer probleme  de lecture fichier exit().....
	char *file_str = "";
	char *w = "";
	w = ft_charlist_to_str(file, ' ');
//	ft_printf("str 1     <%s>\n", w);
	file_str = ft_charlist_to_str(file, SEP);
	// voir s'il ya le char sep dir que fichier contien des caracteres interdis

	if (ft_isempty(file_str))   /// voir si le ficheir est pas vide
		exit(0);

	ft_printf("str 1     <%s>\n\n", file_str);

		
	str = ft_prepare_file(file_str);

	ft_printf("str 2 <%s>\n", str);
	
	char *st = ft_extract_comment(str);
	ft_printf("final str <%s>\n", st);


	ft_strdel(&w);
	ft_strdel(&str);
	ft_strdel(&st);
	ft_strdel(&file_str);
	ft_dell_list_charlist(&file);
	return (0);
}


/*
   int		main()
   {

   char *s2 =  "debwa";
   char *s1 = "aspdonsapdk jou";

   ft_printf("s1  = %d\ns2  = %d\n", ft_strlen(s1), ft_strlen(s2));

   char *result = ft_strjoin_sep(s1,s2,'!');	
   ft_printf("%d   <%s>\n", ft_strlen(result), result );	

   ft_strdel(&result);
   return (0);
   }*/
