/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_symbole.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:26:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 18:48:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

int	ft_is_in_symbole(char *symbole, t_symbole *list)
{
	while (list)
	{

//		ft_printf("{%s} {%s}\n", list->data, symbole);

		if (!ft_strcmp(list->data, symbole))
		{
		
//			ft_printf("{cyan}ret %d{eoc}", list->add);
			return (list->add);
		
		}list = list->next;
	}
	return (-1);
}
