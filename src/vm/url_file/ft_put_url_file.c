/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_url_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:08:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 10:15:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_put_url_file(t_url_file *list)
{
	while (list)
	{
		ft_printf("id %.03d url player[{green}%s{eoc}]\n", list->id, list->url);
		list = list->next;
	}
}
