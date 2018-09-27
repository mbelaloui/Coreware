/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:10:46 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 11:36:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_champ(t_champ *champ)
{
	ft_printf("\n\t/ *********************** \\ \n\n");
	ft_printf("\tid champ : [{green}%.3d{eoc}] \n", champ->id);
	ft_printf("\tname     : [{green}%s{eoc}]\n", champ->name);
	ft_printf("\tcomment  : [{green}%s{eoc}]\n", champ->comment);
	ft_printf("\tsize     : [{green}%d{eoc}]\n", champ->size);
}
