/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_bin_inst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:46:09 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/03 13:34:10 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

int		ft_get_size_bin_inst(int size[SIZE_INST])
{
	int i;
	int somme;

	i = 0;
	somme = 0;
	while (i < SIZE_INST)
	{
		if (size[i] != -1)
			somme += size[i];
		i++;
	}
	return (somme);
}
