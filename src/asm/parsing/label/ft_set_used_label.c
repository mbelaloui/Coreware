/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_used_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:33:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:33:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

void	ft_set_used_label(char *symbole, t_symbole *list)
{
	while (list)
	{
		if (!ft_strcmp(list->data, symbole))
		{
			list->used = T;
			return ;
		}
		list = list->next;
	}
}
