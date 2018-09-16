/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_symbole.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:26:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 13:27:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/asm.h"

int	ft_is_in_symbole(char *symbole, t_symbole *list)
{
	while (list)
	{
		if (!ft_strcmp(list->data, symbole))
			return (list->add);
		list = list->next;
	}
	return (-1);
}
