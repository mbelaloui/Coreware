
#include "../inc/op.h"


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

int	main(int argc, char **argv)
{
	t_charlist *comment;
	t_charlist *file;
	char *url_file = argv[1];
	char *str;

	comment = NULL;
	file = NULL;
	/// cas d'erruer probleme  de lecture fichier exit().....
	if (!ft_read_url_file(url_file, &file))
		return(0) ; 
	char *file_str = "";
	char *w = "";
	w = ft_charlist_to_str(file, ' ');

//	ft_printf("str 1     <%s>\n", w);
	file_str = ft_charlist_to_str(file, SEP);
// voir s'il ya le char sep dir que fichier contien des caracteres interdis

	/// voir si le ficheir est pas vide
	if (ft_isempty(file_str) || ft_is_c_in_str(SEP, w))  
	{
		ft_printf("exit 0 empty file || ~ in the file");
		exit(0);
	}
	//	ft_printf("str 1     <%s>\n\n", file_str);


	str = ft_prepare_file(file_str);

	//	ft_printf("str 2 <%s>\n", str);

	char *st = ft_purification_file(str, &comment);
	ft_printf("file <\n{green}%s{eoc}\n>\n", st);

	//	char **to_display = ft_strsplit(st, '~');
	//	ft_putmat(to_display);
	//	ft_free_mat(&to_display);
	ft_strdel(&w);
	ft_strdel(&str);
	ft_strdel(&st);
	ft_strdel(&file_str);
	ft_dell_list_charlist(&file);
	ft_dell_list_charlist(&comment);
	(void)argc;
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
