/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_indirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:56:48 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/17 19:57:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_read_indirect(t_vm *vm, int add_val)
{
	unsigned char	tab[4];

	tab[0] = vm->mem[(add_val + 0) % MEM_SIZE][MEM_SRC];
	tab[1] = vm->mem[(add_val + 1) % MEM_SIZE][MEM_SRC];
	tab[2] = vm->mem[(add_val + 2) % MEM_SIZE][MEM_SRC];
	tab[3] = vm->mem[(add_val + 3) % MEM_SIZE][MEM_SRC];
	return (ft_byts_to_int(tab));
}