/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:30:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/17 12:05:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/file.h"

static	t_list_fd	*new_buf_fd(int fd)
{
	t_list_fd *temp_result;

	if (!(temp_result = malloc(sizeof(*temp_result))))
		return (NULL);
	temp_result->fd = fd;
	temp_result->rest = NULL;
	temp_result->next = NULL;
	return (temp_result);
}

static	t_list_fd	*get_buf_fd(int fd, t_list_fd **debut)
{
	t_list_fd *list;

	list = *debut;
	if (!list)
	{
		*debut = new_buf_fd(fd);
		return (*debut);
	}
	while ((list->fd != fd) && list->next)
		list = list->next;
	if (list->fd != fd && !list->next)
	{
		list->next = new_buf_fd(fd);
		list = list->next;
	}
	return (list);
}

static	int			read_file_fd(int fd, char **line, char **rest)
{
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		ret;
	char	*temp;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0) && !ft_is_c_in_str('\n', buf))
	{
		temp = *line;
		*line = ft_strjoin(*line, buf);
		ft_strdel(&temp);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	ft_strdel(rest);
	*rest = ft_strnew(BUFF_SIZE);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		(*rest)[i] = buf[i];
	rest[0][i] = '\0';
	temp = *line;
	*line = ft_strjoin(*line, *rest);
	ft_strdel(&temp);
	ft_strdel(rest);
	*rest = ft_strcut(buf, i + 1, ft_strlen(buf));
	return (ret);
}

static	char		*read_file(char **line, char **src)
{
	int		i;
	char	*rest;
	char	*temp;

	rest = ft_strnew(ft_strlen(*src));
	i = 0;
	while ((src[0][i]) && ((src[0][i]) != '\n'))
	{
		rest[i] = src[0][i];
		i++;
	}
	rest[i] = '\0';
	temp = *line;
	*line = ft_strjoin(*line, rest);
	ft_strdel(&temp);
	ft_strdel(&rest);
	rest = ft_strcut(*src, i + 1, ft_strlen(*src));
	ft_strdel(src);
	return (rest);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list_fd	*list;
	t_list_fd			*temp_buf;
	int					result;
	char				*temp;

	result = 1;
	if (fd < 0 || fd > MAXFD || (line == NULL) || !(*line = ft_strnew(0)))
		return (-1);
	temp_buf = get_buf_fd(fd, &list);
	if (!temp_buf->rest || ft_isempty(temp_buf->rest))
		result = read_file_fd(fd, line, &(temp_buf->rest));
	else
	{
		if (ft_is_c_in_str('\n', temp_buf->rest))
			temp_buf->rest = read_file(line, &(temp_buf->rest));
		else
		{
			temp = *line;
			*line = ft_strjoin(*line, temp_buf->rest);
			ft_strdel(&temp);
			result = read_file_fd(fd, line, &(temp_buf->rest));
		}
	}
	return ((ft_strlen(*line) > 0 || result > 0) ? 1 : result);
}
