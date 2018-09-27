/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_nodelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 18:28:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 12:17:56 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nodelist.h"

/*
**   ne peut etre remplacer par new_node(); pas la meme chose
*/

t_nodelist	*ft_new_nodelist(t_node *node)
{
	t_nodelist *ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->node = node;
	ret->next = NULL;
	return (ret);
}
