
#include "../inc/op.h"



/*
** cette fonction permet de prendre en compt les \n
** dans les declations dans le nom et description "  "
** elever les '\n' entre les ""
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
		if (file[i] == DELIMITEUR)
		{
			ret[cp] = file[i];
			cp ++;
			i ++;
			while (file[i] && file[i] != DELIMITEUR)
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
			if (file[i] == DELIMITEUR)
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
	return (ret);
}



/*int	get_index_end_declaration(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == DELIM_DECLARATION)
			return (i + 1);
		i++;
	}
	return (i);
}
*/

/*
** a terminer ajouter les commentaires dans une liste
** split la fonction par apport a chaque type de comment
*/

char	*ft_purification_file(char *file)
{
	int i;
	int index;
	char *ret;
	char *to_add;
	char *to_del;
	
	ret = ft_strnew(ft_strlen(file));
	i = 0;
	int len = ft_strlen(file);
	index = 0;
	while (i < len && file[i])
	{
//	ft_printf("{red}\n 1 \n%s\n\n{eoc}", file +i);
		if (file[i] == SEP)
		{
//	ft_printf("{red}\n 2 \n%s\n\n{eoc}", file +i);
	to_add = ret;
	ret = ft_strjoin(ret, "\n");
//	ft_printf("{yellow}\n %s\n{eoc}", ret);
	ft_strdel(&to_add);
	i++;
		}
		else if(file[i] == '#' || file[i] == ';'
	|| (file[i] && file[i] == '/' && file[i+ 1] == '/'))
		{
	
//	ft_printf("{red}\n 3 \n%s\n\n{eoc}", file +i);
	while (file[i] && file[i] != SEP)
		i++;
		//mettre tout ca dans list comment
		}
		else if (file[i] && file[i] == '/' && file[ i + 1] == '*')
		{
//	ft_printf("{red}\n 4 \n%s\n\n{eoc}", file +i);
	i += 2;
	while (file[i] && file[i] != '*' && file[i + 1] != '/')
	{
		i++;
	}
	if(file[i] && file[i] == '*' && file[i + 1] == '/')
		i += 2;
	//mettre tout ca dans list comment
		}else
		{
//	ft_printf("{red}\n 5 \n%s\n\n{eoc}", file +i);
//	ft_printf("AV i = %d , index = %d \t",i, index);
	index = i + ft_get_index_end_line(file + i);
//	ft_printf("AP i = %d , index = %d \n",i, index);
	to_add = ft_strcut(file,i,index);
	char *to_del = ret;
	ret = ft_strjoin(ret, to_add);
	ft_strdel(&to_add);
	ft_strdel(&to_del);
	i = index;
		//	i++;
		}
		//ft_temporize(2);
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

	if (ft_isempty(file_str) || ft_is_c_in_str(SEP, w))   /// voir si le ficheir est pas vide
	{
		ft_printf("exit 0 empty file || ~ in the file");
		exit(0);
	}
//	ft_printf("str 1     <%s>\n\n", file_str);


	str = ft_prepare_file(file_str);

//	ft_printf("str 2 <%s>\n", str);

	char *st = ft_purification_file(str);
	ft_printf("str f <{green}%s{eoc}>\n", st);


//	char **to_display = ft_strsplit(st, '~');

//	ft_putmat(to_display);

//	ft_free_mat(&to_display);
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
