/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prev_id_urlfile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:09:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/06 11:46:50 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

int		ft_get_prev_id_urlfile(t_url_file *list)
{
	int id;

	id = 0;
	while (list)
	{
		id = list->id + 1;
		list = list->next;
	}
	return (id);
}
