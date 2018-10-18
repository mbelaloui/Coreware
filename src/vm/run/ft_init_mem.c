/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:26:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 16:18:58 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void			put_src_mem(int mem[MEM_SIZE][2], t_vm_inst *list_src,
	int pt, int id_color)
{
	t_int_list	*src;
//	int			start;

//	start = pt;
	id_color = id_color + NULL_COLOR;
	while (list_src)
	{
		src = list_src->src;
		while (src)
		{
			mem[pt][MEM_SRC] = (unsigned char)src->data;
			mem[pt++][MEM_DESC] = id_color;
			src = src->next;
		}
		list_src = list_src->next;
	}
//	mem[start][MEM_DESC] = NULL_COLOR + id_color;
}

static t_int_list	*set_pt_start(t_process *list)
{
	t_int_list *ret;

	ret = NULL;
	while (list)
	{
		ft_add_bgn_intlist(list->pc, &ret);
		list = list->next;
	}
	return (ret);
}

static void			init_null_desc(t_vm *vm)
{
	int pt;

	pt = 0;
	while (pt < MEM_SIZE)
	{
		vm->mem[pt][MEM_DESC] = NULL_COLOR;
		pt++;
	}
}

/*
**	pos; //variable temp pour inverser les address pour ecrire le source code
**	temp_pos; //variable temp pour inverser les address pour ecrire
**			 le source code
*/

void				ft_init_mem(t_vm *vm, t_process *list_process)
{
	t_int_list	*pos;
	t_int_list	*temp_pos;
	t_champ		*champ;
	int			id_color;

	id_color = 1;
	champ = vm->champs;
	pos = set_pt_start(list_process);
	temp_pos = pos;
	init_null_desc(vm);
	while (list_process && champ)
	{
		put_src_mem(vm->mem, champ->src, pos->data, id_color++);
		pos = pos->next;
		list_process = list_process->next;
		champ = champ->next;
	}
	ft_clear_intlist(&temp_pos);
}
