
#include "../inc/op.h"




char    *ft_strjoin_c(char const *str1, char const *str2, const char c)
{
        char    *result;
	int	size_ret;

        if (str1 && str2)
        {
                size_ret = ft_strlen(str1) + ft_strlen(str2);

                ft_printf("1 size = %d \n", size_ret);
		if (!(result = ft_strnew(size_ret)))
                        return (NULL);
                ft_strlcat(result, str1, size_ret);
               // result[ft_strlen(str1)] = c;
                ft_strlcat(result, str2, size_ret + 1);
                return (result);
        }
        return (NULL);
}

int		main()
{
	char s1[] = "bon";
	char s2[] = "jou";

	ft_printf("s1  = %d\ns2  = %d\n", ft_strlen(s1), ft_strlen(s2));	
	char *result = ft_strjoin_c(s1,s2,'*');	
	ft_printf("res = %d <%s>\n", ft_strlen(result), result );	

	return (0);
}
