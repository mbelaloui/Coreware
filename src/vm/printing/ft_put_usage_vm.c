/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_usage_vm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:56:35 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:41:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_usage_vm(void)
{
	ft_printf("Usage :\n"
		"\t./corewar {[-h] [-g] [-v] [-dump [int]]"
		" [[-n number_champ] champion_N.cor] | (n ∈ ℕ) & (n < MAX_int)}.\n");
	exit(1);
}
