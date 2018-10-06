/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_existe_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:10:41 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/06 11:48:59 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_existe_id(int id, t_url_file *list)
{
	while (list)
	{
		if (id == list->id)
			return (T);
		list = list->next;
	}
	return (F);
}
