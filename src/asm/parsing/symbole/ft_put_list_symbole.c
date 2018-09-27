/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_list_symbole.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:31:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 19:31:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

void	ft_put_list_symbole(t_symbole *list)
{
	ft_printf("| ------------- | ------- | ----- |\n");
	ft_printf("|   label\t| address | used  |\n");
	ft_printf("| ------------- | ------- | ----- |\n");
	while (list)
	{
		ft_printf("|   %s\t|   %.3d   | %s\t  |\n",
				list->data, list->add, (list->used) ? "yes" : "no");
		list = list->next;
	}
	ft_printf("| ------------- | ------- | ----- |\n");
}
