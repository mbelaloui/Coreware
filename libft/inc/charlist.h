/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:45:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/14 11:37:16 by mbelalou         ###   ########.fr       */
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
t_charlist				*ft_new_charlist(const char *data);
BOOL					ft_add_charlist(char *data, t_charlist **list);

BOOL					ft_dell_charlist(t_charlist **to_free);
BOOL					ft_dell_list_charlist(t_charlist **to_free);
BOOL					ft_isempty_charlist(t_charlist *list);

size_t					ft_size_charlist(const t_charlist *list);

#endif
