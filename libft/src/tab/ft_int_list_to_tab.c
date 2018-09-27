/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_list_to_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:02:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/01 13:38:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tab.h"

void	ft_int_list_to_tab(intmax_t **dest, t_int_list *src, int size)
{
	int pt;

	pt = -1;
	while (size--)
	{
		(*dest)[++pt] = src->data;
		src = src->next;
	}
}
