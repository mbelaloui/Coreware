/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_for_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:55:14 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 19:56:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int	ft_search_for_op(char **tab, t_vm_option *op_vm)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == '-' && tab[i][1] != 'n')
			i += ft_extract_vm_op(tab + i, op_vm);
		else
			return (i);
	}
	return (i);
}
