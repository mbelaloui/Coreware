
#include "../inc/op.h"



int		main()
{
	char *s2 =  "debwa";
	char *s1 = "aspdonsapdk jou";

	ft_printf("s1  = %d\ns2  = %d\n", ft_strlen(s1), ft_strlen(s2));

	char *result = ft_strjoin_sep(s1,s2,'!');	
	ft_printf("%d   <%s>\n", ft_strlen(result), result );	

	ft_strdel(&result);
	return (0);
}
