/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:23:59 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/20 12:47:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

t_int_list	*ft_backtrack_path(t_nodelist *listnode, int id_end, int id_start)
{
	t_int_list	*list_father;
	t_int_list	*path;
	int			id_father;

	path = NULL;
	ft_add_bgn_intlist(id_end, &path);
	list_father = ft_get_father(id_end, listnode);
	while ((id_father = ft_get_id_best_father(list_father, listnode)) > -1
			&& id_father)
	{
		ft_add_bgn_intlist(id_father, &path);
		ft_clear_intlist(&list_father);
		list_father = ft_get_father(id_father, listnode);
	}
	ft_clear_intlist(&list_father);
	if (!ft_is_in_intlist(id_start, path))
		ft_add_bgn_intlist(id_start, &path);
	return (path);
}
