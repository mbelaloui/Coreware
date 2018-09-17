/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 01:03:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/05 20:09:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/file.h"

int		ft_open_file(char *url_file)
{
	int fd;

	if (url_file == NULL)
		return (-1);
	fd = open(url_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
