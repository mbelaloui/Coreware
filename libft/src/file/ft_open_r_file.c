/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_r_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:48:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 13:35:22 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/file.h"

int		ft_open_r_file(const char *url_file)
{
	int fd;

	if (url_file == NULL)
		return (ERROR_URL_FILE);
	fd = open(url_file, O_RDONLY);
	if (fd < 0)
		return (ERROR_FD);
	return (fd);
}
