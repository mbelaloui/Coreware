/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good_format_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:08:49 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/26 12:12:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

BOOL	ft_is_good_format_file(char *url_file)
{
	char **temp;

	temp = ft_strsplit(url_file, '.');
	if (ft_matlen(temp) != 2)
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url_file);
	if (temp[1][0] != 's')
		ft_error_param(ERROR_WRONG_FORMAT_FILE, url_file);
	return (T);
}
