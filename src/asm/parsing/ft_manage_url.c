/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_url.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:39:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 12:04:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

char	*ft_manage_url(char *url)
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
	url_output = ft_strjoin(temp[0], FORMAT_OUTPUT);
	ft_strdel(&file_name);
	ft_free_mat(&temp);
	return (url_output);
}
