/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:07:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 17:36:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

static void	ft_dell_inst_src(t_vm_inst **to_free)
{
	t_vm_inst *pt;
	t_int_list*temp;

	if (!to_free || !(*to_free))
		return ;
	pt = *to_free;
	while (*to_free)
	{
		pt = *to_free;
		temp = pt->src;
		ft_clear_intlist(&temp);

		/*
		**	ft_printf("----------------\n");
		**	ft_put_hex_intlist(temp);
		**	ft_printf("----------------\n");
		*/

		*to_free = (*to_free)->next;
		free(pt);
	}
	*to_free = NULL;
}


void	ft_dell_champ(t_champ **champ)
{
	char	*name;
	char	*com;

	name = (*champ)->name;
	ft_strdel(&name);
	com = (*champ)->comment;
	ft_strdel(&com);
	ft_dell_inst_src(&(*champ)->src);
	free(*champ);
}
