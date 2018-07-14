#include "../../inc/str.h"

char    *ft_strjoin_sep(char const *str1, char const *str2, const char c)
{
        char    *result;
        int     size_ret;

        if (str1 && str2)
        {
                size_ret = ft_strlen(str1) + ft_strlen(str2) + 1;
                if (!(result = ft_strnew(size_ret)))
                        return (NULL);
                ft_strlcat(result, str1, size_ret);
                result[ft_strlen(str1)] = c;
                ft_strlcat(result, str2, size_ret + 1);
                return (result);
        }
        return (NULL);
}

