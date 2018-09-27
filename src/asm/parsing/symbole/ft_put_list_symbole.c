/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_list_symbole.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:31:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 13:59:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

void	ft_put_list_symbole(t_symbole *list)
{
	ft_printf("|\t-----\t\t|\t-------\t|\t-----\t|\n");
	ft_printf("|\tlabel\t\t|\taddress\t|\tused\t|\n");
	ft_printf("|\t-----\t\t|\t-------\t|\t-----\t|\n");
	while (list)
	{
		ft_printf("|\t%s\t\t|\t%d\t|\t %s\t|\n",
				list->data, list->add, (list->used) ? "yes" : "no");
		list = list->next;
	}
	ft_printf("|\t-----\t\t|\t-------\t|\t-----\t|\n");
}
