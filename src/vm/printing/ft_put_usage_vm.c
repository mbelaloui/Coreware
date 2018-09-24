/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_usage_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:56:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/24 16:57:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	ft_put_usage_vm(void)
{
	ft_printf("Usage :\n ./corewar {-a champ.s} {[-v] [-dump [int]]"
			" [[-n number_champ] champion_N.cor]} n ∈ [1,2,3,4].\n");
	exit(1);
}
