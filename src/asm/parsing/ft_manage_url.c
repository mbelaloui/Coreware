/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_url.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:39:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/22 14:26:38 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

static char	*get_url(char *url, char *name_file)
{
	char	*ret;
	char	**temp;
	int		pt;
	int		pt_end;
	char	*sep;

	sep = "/";
	temp = ft_strsplit(url, '/');
	pt_end = ft_matlen(temp);
	pt = 0;
	ret = NULL;
	while (pt < pt_end - 1)
	{
		ret = ft_strjoin_clear(&ret, &temp[pt], FIRST);
		ret = ft_strjoin_clear(&ret, &sep, FIRST);
		pt++;
	}
	ret = ft_strjoin_clear(&ret, &name_file, FIRST);
	ft_free_mat(&temp);
	return (ret);
}

char		*ft_manage_url(char *url)
{
	char	**temp;
	char	*url_output;
	char	*file_name;
	int		pt_end;

	if (ft_isempty(url))
		ft_error_param(ERROR_NO_PARAM, url);
	if (ft_comptword(url, ' ') != 1)
		ft_error_param(ERROR_MULTIPUL_PARAM, url);
	temp = ft_strsplit(url, '/');
	pt_end = ft_matlen(temp);
	file_name = ft_strdup(temp[pt_end - 1]);
	ft_free_mat(&temp);
	temp = ft_strsplit(file_name, '.');
	if (ft_matlen(temp) != 2 || ft_strcmp(temp[1], FORMAT_INPUT))
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url);
	ft_strdel(&file_name);
	file_name = ft_strjoin(temp[0], FORMAT_OUTPUT);
	url_output = get_url(url, file_name);
	ft_strdel(&file_name);
	ft_free_mat(&temp);
	return (url_output);
}
