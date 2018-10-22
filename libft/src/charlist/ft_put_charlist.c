/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_charlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:35:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 14:49:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

void	ft_put_charlist(t_charlist *list)
{
	if (!list)
		ft_printf("(NULL)\n");
	else
		ft_printf("%s", list->data);
}
