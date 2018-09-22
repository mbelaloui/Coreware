/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_charlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:15:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/30 19:18:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

size_t		ft_size_charlist(const t_charlist *list)
{
	size_t size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
