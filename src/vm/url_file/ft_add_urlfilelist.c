/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_urlfilelist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:01:58 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:44:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_add_urlfilelist(int id, char *url, t_url_file **list)
{
	t_url_file *temp;

	if (!(temp = ft_new_url_file(id, url)))
		return (F);
	if (*list == NULL)
		*list = temp;
	else
	{
		temp->next = *list;
		*list = temp;
	}
	return (T);
}
