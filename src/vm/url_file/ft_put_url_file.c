/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_url_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:08:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/19 14:57:39 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_url_file(t_url_file *list)
{
	while (list)
	{
		ft_printf("num %.03d url player[{green}%s{eoc}]\n",
			list->num, list->url);
		list = list->next;
	}
}
