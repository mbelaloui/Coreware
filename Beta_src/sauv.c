
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

BOOL	is_stop_char(char *str)
{
	if (str[0] == COMMENT_CHAR || str[0] == COMMENT_CHAR_1
		|| str[0] == SEP)
		return (T);
	if (str[0] == COMMENT_CHAR_2 && (str[1] == COMMENT_CHAR_3
		|| str[1] == COMMENT_CHAR_2))
		return (T);
	return (F);
}

int	get_index_end_line(char *str)
{
	int i = 0;

	while (str[i] && !is_stop_char(str + i))
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
				
		}
		if (str[i])
			i++;
		//ft_printf("{green}dasd sa{eoc}", str[i]);
	}
//	ft_printf("\tend  = %d \n", i);
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
	int len = ft_strlen(file);
	while (i < len && file[i])
	{
	//	ft_printf(" 1 {yellow}sdvsdvsd{eoc} %c\n", file[i]);
	/*	if (file[i] == DELIM_DECLARATION)
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
*/
		if (file[i] == SEP)
		{
			to_add = ret;
			ret = ft_strjoin(ret, "~");
			ft_strdel(&to_add);
	//		ft_printf(" 2 {cyan} %d{eoc} %c -  %c\n",
	//		i,file[i] , file[i - 1],i);
			i++;
		}else if(file[i] == '#' || file[i] == ';')
		{
			while (file[i] && file[i] != SEP)
				i++;
				//mettre tout ca dans list comment
		}
		else
		{
//ft_printf("AA i = %d , index = %d \t",i, index);
			index = i + get_index_end_line(file + i);
//		ft_printf("get to_add  i = %d , index = %d -<%s> \n"
//			,i, index, ft_strcut(file,i,index));
			to_add = ft_strcut(file,i,index);
//ft_printf("befor join str <%s> to add <%s> \n",ret, to_add);
			char *to_del = ret;
			ret = ft_strjoin(ret, to_add);
			ft_strdel(&to_add);
			ft_strdel(&to_del);
//	ft_printf("after join {green}str <%s> mto add <%s> {eoc} \n",ret, to_add);
			i = index;
		}
		//	i++;
		//ft_temporize(2);
		//ft_printf("{red}sdvsdvsd{eoc}\n");
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