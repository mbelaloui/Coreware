/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:10:46 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 09:12:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_champ(t_champ *champ)
{
	ft_printf("\n\t/ *********************** \\ \n\n");
	ft_printf("\tnum champ      : [{green}%15.3d{eoc}] \n", champ->num);
	ft_printf("\tpos champ      : [{green}%15.3d{eoc}] \n", champ->pos);
	ft_printf("\tname           : [{green}%15s{eoc}]\n", champ->name);
//	ft_printf("\tcomment        : [{green}%15{eoc}]\n", champ->comment);
	ft_printf("\tsize           : [{green}%15.3d{eoc}]\n", champ->size);
}
