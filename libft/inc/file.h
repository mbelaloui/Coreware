/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:14:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/10 17:13:52 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "libft.h"

# define BUFF_SIZE	4096
# define MAXFD		4864
# define ERROR_URL_FILE -1
# define ERROR_FD       -2

typedef struct			s_list_fd
{
	int					fd;
	char				*rest;
	struct s_list_fd	*next;
}						t_list_fd;

int						ft_open_r_file(char *url_file);
int						get_next_line(const int fd, char **line);

#endif
