#include "../../../inc/asm.h"

char	*ft_manage_url(char *url)
{
	char **temp;
	char *url_output;

	if (ft_comptword(url, ' ') != 1)
		ft_error_param(ERROR_MULTIPUL_PARAM, url);
	temp = ft_strsplit(url, '.');
	if (ft_matlen(temp) != 2 || ft_strcmp(temp[1], FORMAT_INPUT))
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url);
	url_output = ft_strjoin(temp[0], FORMAT_OUTPUT);
	ft_free_mat(&temp);
	return(url_output);
}
