/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_list_symbole.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:31:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/30 19:36:51 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

void	ft_put_list_symbole(t_symbole *list)
{
	ft_printf("+ --------------------- + ------- + ----- +\n|   label\t \t|"
	" address | used  |\n| --------------------- | ------- | ----- |\n");
	while (list)
	{
		ft_printf("| %-*s \t|   %.3d   | %s\t  |\n", SIZE_SYMBOLE_LABEL,
		list->data, list->add, (list->used) ? "yes" : "no");
		list = list->next;
	}
	ft_printf("+ --------------------- + ------- + ----- +\n");
}
