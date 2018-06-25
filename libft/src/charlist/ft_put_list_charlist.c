/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_charlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:35:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/03 11:57:21 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

void	ft_put_list_charlist(t_charlist *list)
{
	if (list)
		while (list)
		{
			ft_printf("%s\n", list->data);
			list = list->next;
		}
}
