/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_urlfilelist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:01:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/06 11:17:19 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_urlfilelist(int id, char *url, t_url_file **list)
{
	t_url_file		*temp;
	t_url_file		*pt_list;

	if (!(temp = ft_new_url_file(id, url)))
		return (F);
	if (!(*list))
		*list = temp;
	else
	{
		pt_list = *list;
		while (pt_list->next)
			pt_list = pt_list->next;
		pt_list->next = temp;
	}
	return (T);
}
