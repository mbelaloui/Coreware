/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:18:04 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/20 10:18:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void		ft_put_to_mem(int add, int val, t_process *process, t_vm *vm)
{
	unsigned char	*tab;
	int				max_print;

	tab = ft_int_to_byts((unsigned)val, DIR_SIZE);
	max_print = add + DIR_SIZE;
	while (add < max_print)
	{
		vm->mem[add % MEM_SIZE][MEM_SRC] = tab[DIR_SIZE - (max_print - add)];
		vm->mem[add % MEM_SIZE][MEM_DESC] = process->id_parent + NULL_COLOR;
		add++;
	}
	free(tab);
}