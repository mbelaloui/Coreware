/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prev_num_urlfile.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:09:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 08:46:02 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_prev_num_urlfile(t_url_file *list)
{
	int num;

	num = -1;
	while (list)
	{
		num = list->num - 1;
		list = list->next;
	}
	return (num);
}
