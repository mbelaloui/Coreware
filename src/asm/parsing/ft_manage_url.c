#include "../../../inc/asm.h"

void	ft_manage_url(char *url)
{
	char **temp;

	if (ft_comptword(url, ' ') != 1)
		ft_error_param(ERROR_MULTIPUL_PARAM, url);
	temp = ft_strsplit(url, '.');
	if (ft_matlen(temp) != 2 || ft_strcmp(temp[1], "s"))
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url);
	ft_free_mat(&temp);
}
