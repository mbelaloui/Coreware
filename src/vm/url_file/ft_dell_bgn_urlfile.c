/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_bgn_urlfile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:04:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:05:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"


BOOL	ft_dell_bgn_urlfile(t_url_file **list)
{
	t_url_file *to_free;

	if ((*list) == NULL)
		return (F);
	to_free = *list;
	if (!(*list)->next)
		*list = NULL;
	else
		*list = (*list)->next;
	ft_dell_urlfile(&to_free);
	return (T);
}
