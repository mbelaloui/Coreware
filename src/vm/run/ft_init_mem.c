/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:26:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 10:29:28 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void put_src_mem(int mem[MEM_SIZE][2], t_vm_inst *list_src, int start,
    int pos)
{
	t_int_list *src;
	int pt;

	pt = start;
	while (list_src)
	{
		src = list_src->src;
		while (src)
		{
			mem[pt][MEM_SEC] = (unsigned char)src->data;
			mem[pt++][MEM_DESC] = pos;
			src = src->next;
		}
		list_src = list_src->next;
	}
}

void	ft_init_mem(t_vm *vm, t_process *list_process)
{
	t_champ *champ;
	int     start;
	int      pos;

	pos = 1;
	champ = vm->champs;
	while (list_process && champ)
	{
		start = list_process->pc;
		put_src_mem(vm->mem, champ->src, list_process->pc, pos++);
		list_process = list_process->next;
		champ = champ->next;
	}
}
