/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_intlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:16:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 13:17:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/list.h"

t_int_list		*ft_new_intlist(const intmax_t nbr)
{
	t_int_list		*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->data = nbr;
	ret->next = NULL;
	return (ret);
}
