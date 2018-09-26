/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:20:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 15:43:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

int	ft_get_index_end(char *str_file)
{
	int i;
	int num_sep;

	num_sep = 2;
	i = 0;
	while (str_file[i] && num_sep > 0)
	{
		if (str_file[i] == DEF)
			num_sep--;
		i++;
	}
	if (num_sep && !str_file[i])
		return (-1);
	return (i);
}
