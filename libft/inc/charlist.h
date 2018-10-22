/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:45:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 13:49:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARLIST_H
# define CHARLIST_H

# include "libft.h"

typedef struct			s_charlist
{
	char				*data;
	struct s_charlist	*next;
}						t_charlist;

void					ft_put_charlist(t_charlist *data);
void					ft_put_list_charlist(t_charlist *data);
void					ft_put_list_charlist_join(t_charlist *data);
t_charlist				*ft_new_charlist(const char *data);
BOOL					ft_add_charlist(char *data, t_charlist **list);

BOOL					ft_dell_charlist(t_charlist **to_free);
BOOL					ft_dell_list_charlist(t_charlist **to_free);
BOOL					ft_isempty_charlist(t_charlist *list);

size_t					ft_size_charlist(const t_charlist *list);

BOOL					ft_cp_list_charlist(t_charlist *src, t_charlist **dest);
BOOL					ft_cut_add_charlist(char *src, int start, int max_size,
		t_charlist **dest);

BOOL					ft_read_url_file(const char *url, t_charlist **file);
BOOL					ft_read_fd_file(const int fd, t_charlist **file);

char					*ft_charlist_to_str(t_charlist *list, char c);
char					*ft_charlist_to_format_str(t_charlist *list, char c);
t_charlist				*ft_str_to_format_charlist(char *str, char sep);

t_charlist				*ft_str_to_charlist(char *str, char sep);
t_charlist				*ft_mat_to_charlist(char **mat);

#endif
