/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_listchamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:36:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 16:07:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_listchamp(t_champ *list)
{
	while (list)
	{
		ft_put_champ(list);
		ft_put_inst_src_vm(list->src);
		list = list->next;
	}
}
