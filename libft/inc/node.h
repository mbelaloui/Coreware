/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:38:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/19 15:22:04 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "list.h"

/*
** changer les int x et int y en char *
** et les free en del just auqnd ont dell le noeud
** ft_get_room
*/

typedef struct			s_node
{
	int					id;
	intmax_t			x;
	intmax_t			y;
	int					stats;
	int					dist;
	int					id_father;
	char				*name;
	t_int_list			*list_neighbors;
}						t_node;

BOOL					ft_dell_node(t_node **node);
t_node					*ft_new_node(int id, char *name,
		intmax_t x, intmax_t y);
void					ft_put_node(t_node *node);

#endif
