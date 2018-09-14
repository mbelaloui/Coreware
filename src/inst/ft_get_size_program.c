/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_program.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:04:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:06:05 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int	ft_get_size_program(t_instlist *list)
{
	int size_program;

	size_program = 0;
	while (list)
	{
		size_program += list->data->size_inst;
		list = list->next;
	}
	return (size_program);
}
