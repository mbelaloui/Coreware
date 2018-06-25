#include "../../inc/asm.h"

BOOL            ft_is_good_format_file(char *url_file)
{
        char **temp;
       
	temp = ft_strsplit(url_file, '.');
        if (ft_matlen(temp) != 2)
                ft_error_param(ERROR_WRONG_FORMAT_FILE, url_file);
        if ( temp[1][0] != 's')
                ft_error_param(ERROR_WRONG_FORMAT_FILE, url_file);
        return (T);
}
