/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:28:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 16:40:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

/*
** int p = 3;
**	while (pt < 4)
**		ta	b[pt++]=0;*
**	pt = 0;
**	ft_printf(" \n");
**	while (pt < size)
**	{
***		ft_printf(" src{%d} = %x  ",pt, src[pt]);
**		tab[p] = src[pt];
**		pt++;
**		p--;
**	}
**	//fonction byte to int et ajouter le resultat a la list
**
**	int q = ft_byts_to_int(tab);
**	ft_printf("{%d} [%d] [%d] [%d] [%d]\n",q, tab[0] ,tab[1] ,tab[2], tab[3] );
**	ft_printf("size {%d}  ",size);
**
**	ft_add_end_intlist(q, inst_src);
*/

static int	add_to_inst(char *src, t_int_list **inst_src, int size)
{
	int pt;

	pt = 0;
	while (pt < size)
		ft_add_end_intlist(src[pt++], inst_src);
	return (size);
}

static int	manage_param_desc(char *src, t_int_list **inst_src_list,
		t_op *op, t_op *op_tab[NBR_OP])
{
	unsigned char	desc;
	int				size;
	int				pt;

	pt = 0;
	desc = src[pt++];
	ft_add_end_intlist(desc, inst_src_list);
	add_to_inst(src + pt, inst_src_list, size = ft_manage_p1(desc, op,
				op_tab));
	pt += size;
	if (op->nbr_param > 1)
	{
		add_to_inst(src + pt, inst_src_list, size = ft_manage_p2(desc, op,
					op_tab));
		pt += size;
		if (op->nbr_param > 2)
		{
			add_to_inst(src + pt, inst_src_list, size = ft_manage_p3(desc, op,
						op_tab));
			pt += size;
		}
	}
	return (pt);
}

int			ft_manage_param(char *src, t_op *op, t_int_list **inst_src_list,
		t_op *op_tab[NBR_OP])
{
	int			nbr_oct;
	int			pt;

	pt = 0;
	if (!ft_is_need_desc_op(op->name, op_tab))
	{
		nbr_oct = (op->mnemonique == 1) ? 4 : 2;
		add_to_inst(src + pt, inst_src_list, nbr_oct);
		pt += nbr_oct;
	}
	else
		pt += manage_param_desc(src + pt, inst_src_list, op, op_tab);
	return (pt);
}
