/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_vm_url.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:56:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 19:57:09 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_manage_vm_url(char *url)
{
	char	*file_name;
	char	**temp;
	int		pt_end;

	if (ft_isempty(url))
		ft_error_param_vm(ERROR_NO_PARAM,url);
	temp = ft_strsplit(url, '/');
	pt_end = ft_matlen(temp);
	file_name = ft_strdup(temp[pt_end - 1]);
	ft_free_mat(&temp);
	temp = ft_strsplit(file_name, '.');
	if (ft_matlen(temp) != 2 || ft_strcmp(temp[1], FORMAT_INPUT_VM))
		ft_error_param_vm(ERROR_NO_PARAM_ID, url);
	ft_strdel(&file_name);
	ft_free_mat(&temp);
	return (T);
}
