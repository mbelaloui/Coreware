/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:13:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 12:17:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/node.h"

t_node		*ft_new_node(int id, char *name, intmax_t x, intmax_t y)
{
	t_node *ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id = id;
	ret->name = name;
	ret->x = x;
	ret->y = y;
	ret->stats = 0;
	ret->dist = -1;
	ret->id_father = -1;
	ret->list_neighbors = NULL;
	return (ret);
}
