/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good_format_urlfile.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 14:00:10 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/29 15:23:12 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_good_format_urlfile(char *url_file)
{
	char **temp;

	temp = ft_strsplit(url_file, '.');
	if (ft_matlen(temp) != 2)
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url_file);
	if (temp[1][0] != 's')
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url_file);
	return (T);
}
