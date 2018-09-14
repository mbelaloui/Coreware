/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_instlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:22:53 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 16:23:18 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_put_instlist(t_instlist *list)
{
	int size_program;

	size_program = 0;
	while (list)
	{
		ft_printf(" +++++++++++++++++++++++++++++++++++++++++++++++++\n");
		ft_put_inst(list->data);
		size_program += list->data->size_inst;
		list = list->next;
	}
	ft_printf("size programme {green}%d{eoc} \n", size_program);
}
