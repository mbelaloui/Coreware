/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_charlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:35:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/11 12:11:27 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

void	ft_put_list_charlist_join(t_charlist *list)
{
	while (list && list->data)
	{
		ft_printf("%s", list->data);
		list = list->next;
	}
}
