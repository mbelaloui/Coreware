/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:51:05 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 13:48:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

BOOL	ft_read_fd_file(const int fd, t_charlist **file)
{
	char *line;

	if (fd < 0 || fd > MAX_FD)
		return (F);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_add_charlist(line, file);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (T);
}
