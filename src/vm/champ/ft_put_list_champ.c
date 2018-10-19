/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_list_champ.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:03:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 15:03:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_list_champ(t_champ *list_champ)
{
	while (list_champ)
	{
		ft_put_champ(list_champ);
		list_champ = list_champ->next;
	}
}
